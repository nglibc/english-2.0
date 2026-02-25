#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/types.h>
#include <regex.h>

/* English 2.0 release 0.1 (February 2026)                                    */
/*                                                                            */
/* EXECUTIVE SUMMARY                                                          */
/*                                                                            */
/* English 2.0 preserves familiar spelling while offering an easy way to show */
/* true pronunciation when needed. It halves current English complexity by    */
/* reducing two parallel Long Vowel systems (Magic E and Vowel Teams) to just */
/* the latter.  Vowel teams & consonants are also simplified so that English  */
/* becomes clearer without losing its history.                                */
/*                                                                            */
/* This system is aims for simplicity & orthogonalilty, so that pronunciation */
/* of the general lexicon can be specified within 120 lines (80 columns) of   */
/* formal rules. The regular rule pattern also provides strong guidance for   */
/* writing, often cutting ambiguity down to 2-3 homophone choices or less.    */
/*                                                                            */
/* 1. TWO MODES OF ENGLISH 2.0:                                               */
/*                                                                            */
/* -  APPROXIMATION MODE: A frictionless, familiar script for daily typing.   */
/*    It retains traditional word shapes & many heritage spellings. By using  */
/*    only the ASCII character set, it is universally compatible.             */
/* -  FIDELITY MODE: The high-resolution version of the language. It uses the */
/*    diaeresis (¨) to provide explicit phonetic fidelity. It signals exactly */
/*    where syllables break and where sounds decay.                           */
/* -  FRICTIONLESS TRANSITION: Because diaeresis is only non-ASCII feature,   */
/*    the transition between modes is purely the adding or stripping of dots. */
/*    Exception: Fidelity voiceless (tħink) uses tħ and voiced (the) uses th. */
/*                                                                            */
/* Together, these modes bridge the gap between historical heritage and       */
/* modern phonetic logic without requiring a massive rewrite of the lexicon.  */
/*                                                                            */
/* 2. PRE-PROCESSING: CONSONANT SPECIALISATION & PHONETIC REFINEMENT          */
/*                                                                            */
/* - Soft 'c' mandate: 'c' restricted to ce/ci/cy/ch/ck or /ʃ/ else 'c'=>'k', */
/*   where /ʃ/ occurs in the trigraphs -(ci/ti)[aeiou] (without diaeresis).   */
/* - Soft 'g' mandate: 'g'=>'j' for gy/ge/gi (non Germanic); otherwise 'g'.   */
/* - Buzzed 's': becomes 'z', except word-final 's' keeps 's' even if buzzed, */
/*   hence plurals, possessives, functional (as, is, was, has, does) use 's'. */
/* - Buzzed 'x': 'xz' btw vowels or before voiced consonants, else just 'x'.  */
/* - W words: wone/wonce & one/once spelt with 'o' (see also Scribal O below),*/ 
/* - QU/GU words: word-initial qu/gu always retain u; drop medial silent u.   */
/*                                                                            */
/* 3. MID-PROCESSING: REVERSE MAGIC E (RME)                                   */
/*                                                                            */
/* Having two systems for Long Vowels (Magic E vs Vowel teams) is duplication */
/* of complexity. English 2.0 reduces this to one (in the general lexicon):   */
/* - Liquidation of Silent Magic E (LongV-C-e) in favor of Vowel-E (V-e-C).   */
/* - Short vowel (eg. Scribal O) words must be protected from RME processing. */
/* - Fixed Teams: ae, ee, iy, oe, ue - eg. gate=>gaet, rode=>roed, some=>some */
/*                                                                            */
/* Treatment of -ite/ide/ire words, and -ate verbs:                           */
/* - General Lexicon: if end is Long Vowel => -iy/ae RME (except -itë below). */
/* - Science Name Registries: all of these also retain existing trigraphs.    */
/* - Hence common science words are dual forms (eg. carbonaeted, carbonated). */
/* - Dual form iff [scientific registry && common usage]. ~20 words/top 50K.  */
/*                                                                            */
/* Treatment of -ice/ive/ine/ile words, and -ate nouns:                       */
/* - Generally only atomic (1 syllable) are Long I => RME applies to these.   */
/* - The -pile/file/koncile non-atomics also Long I -ile => iyl RME words.    */
/* - The -b/f/l/n/p/sh/w/vine non-atomics are Long I -ine => iyn RME words.   */
/*   (note: give, masculinë, femininë, disciplinë: no RME, retain -e).        */
/*                                                                            */
/* Treatment of are/ere/ore/ure words:                                        */
/* - Always short R-Controlled Vowels +/- unstressed => RME does not apply.   */
/*                                                                            */
/* 4. POST-PROCESSING: REGULARISE REMAINING -E                                */
/*                                                                            */
/* - Terminal E: RME collapses terminal 'e' into Scribal/Geovariant mark.     */
/* - Scribal O: must end in 'e', 'er' or 'ey' (some, love, mother, money).    */
/* - Protective 'e': -ce/je/se/ve (never bare ending), -iyze & u-glide words. */
/* - Guard to 's[^s]': distinguishes singular (buse, gase, irise) vs plural.  */
/* - Noun Reduced Vowel -ate: signals noun form of '-aet' verb (isolate).     */
/* - USA Short Vowel -ile: signals dialect swing (same spelling for USA & UK) */
/* - French Vowel -ine: signals Long E (machine vs femininë/masculinë).       */
/* - Romance markers -e, -ion, -ic, -ment, -able/el: are result but not rule. */
/*                                                                            */
/* 5. SHORT VOWEL SPECIALISATION                                              */
/*                                                                            */
/* Schwa representation remains a shortcoming (no direct representation).     */
/* Short vowels are single vowels. Vowel teams are described in next section. */
/* Word-final letter vowels are Long (O, U), Schwa/Broad (A) or Silent (E).   */
/* Word-initial Long 'O' if multisyllable word & single consonant after O.    */
/*                                                                            */
/* a       Short A /æ/, except for AR /ɔr/ digraphs. Broad A /ɑ/ is accepted  */
/*         as alternative in many words & mandatory in most 'wa' words.       */
/* e       Short E /ɛ/, ~/ɪ/(if unstressed prefixes: be-, de-, re-).          */
/* i       Short I /ɪ/, except for atomic 'I'.                                */
/* o       Short O /ɑ~ɒ/, except for Scribal O and Long OO (in to, do, who).  */
/* u       Short U /ʌ/, ~/ə/(if unstressed) or Short OO (puyt, fuyll, puysh). */
/*                                                                            */
/* 6. OTHER VOWEL SPECIALISATION                                              */
/*                                                                            */
/* Vowels can be (a) internal to word, (b) terminal at end of word/root word, */
/* (c) junctional (two separate syllables), (d) atomic 1-syllable root word.  */
/*                                                                            */
/* Some vowel teams are denoted as "swing". These teams vary in pronunciation */
/* between dialects, but have same (global) spelling regardless of dialect.   */
/* Characterisation as "Romance" or "Germanic" is approximate, not absolute.  */
/*                                                                            */
/* ai/ae   Internal Long A. Stressed (rain, staek on plaet, paeling staek).   */
/*         Used by Germanic roots. Unstressed Romance decay uses ï (captaïn). */
/* ate     Scientific Terminal Long AT. Stressed. In contrast -atë is at-ë.   */
/* ay      Terminal Long A (day, pray). Unlike -ey, it doesn't decay.         */
/*         Remains a sharp Long A even if unstressed (holiday).               */
/* au      Broad AW diphthong (wauter, kaughf, traughf).                      */
/* iy/ify  Standard/Terminal Long I. Stressed (subliym, justify, hydroliyze). */
/* igh     Germanic Terminal Long I. Stressed/heavy (fligh, drigh, sligh).    */
/* ite/ide Scientific Terminal Long IT/ID. Stressed. In contrast -itë is it-ë */
/*         junction (eg. favoritë, -o/-isitë, -ueritë, elitë/petitë/suitë).   */
/* i[^td]e Terminal Swing /ɪ~i/. Unstressed suffixes (-ile/ne/ce/ve/se).      */
/*         Atomics & Long I derivs move to iy lane (eg. viyce, liyn, hiyve).  */
/* y       Terminal Swing /ɪ~i/. Unstressed multi-syllables (happy, carry).   */
/*         Atomic Long I (why). Non-atomic+stress uses ÿ/ify (supplÿ=suppl-y).*/
/* ie      Junctional Swing /ɪ~i/. Unstressed. Diaeresis is break (happiëst). */
/*         Atomic Long I (eg. die, pie).                                      */
/* ey      Terminal Swing /ɪ~i/. Unstressed. Scribal marker for O (honey).    */
/*         Atomic Long A (they, hey). Evict non-atomic+stress to 'ay' (obay). */
/* ei      Multisyllable Long E (receive, deceit). Atomic Long A (eight, vein)*/
/* ea/ee   Standard Long E (feel, meet). Distinguishes Germanic roots from    */
/*         the Romance 'ie' lane.                                             */
/* oa/oe   Standard Long O (boat, road, toe). Used for Germanic roots where   */
/*         vowel is internal 'oa' followed by consonant, or terminal 'oe'.    */
/* ow      Terminal Lazy O (yellow). Suffixing -er/-ed (lowër) has diaresis.  */
/*         Atomic Long O (low, grow).                                         */
/* ou      Internal OW diphthong /aʊ/ (house, cloud, south).                  */
/*         Long OO words are evicted to 'ue' (eg. soup=>suep).                */
/* oü      Junction with short U collapse (doübel, koüntry).                  */
/* ow[n]e  Internal & terminal OW diphthong (howe, towne, scowel, flower).    */
/*         Note: Reverse magic E rule transforms (only) 'owe' to 'oew'.       */
/* oo/ue   Details TBD. Scribal O rules apply to flo/blo-od (bloode, floode). */
/* ar      Standard R-Controlled AR /ɑr/ (arë, far).                          */
/* are/air Terminal R-Controlled AIR /ɛr/ (hare, hair; evict word are=>arë).  */ 
/* ear/eer Terminal R-Controlled EAR /ɪr/ (near, heer; evict bear=>bere).     */ 
/* ere     Multisyllable R-Controlled EAR /ɪr/ (sincere). Stressed.           */ 
/*         Atomic R-Controlled AIR /ɛr/ sound (where, there; evict here=>ee). */ 
/* er/ur   Romance R-Controlled Vowel IR/ER /ɝ~ər/ (nurse, serve).            */
/*         or Scribal O family (other, mother & bother to have 'o' = /ʌ/).    */
/* ir      Germanic Metathesis R-Controlled Vowel IR/ER /ɝ~ər/ (bird).        */
/* or/ore  R-Controlled Vowel OR /ɔr/ (for, more). Note 'ore' not Scribal O). */ 
/* wor     R-controlled vowel + W-glide (work, word): use 'o' transition mark */
/* ough    Terminal Long O words only. Evict all others to -owe (plowe),      */
/*         -ue (thru), -aught (baught) or -aughf (kaughf).                    */
/* ure     Terminal R-Controlled URE.                                         */ 
/*                                                                            */
/* 7. DOUBLE CONSONANT SPECIALISATION                                         */
/*                                                                            */
/* Double consonants mark stressed final short vowels of the base word. They  */
/* are not needed in initial syllables, which are stressed by default, if the */
/* final syllable is not stressed. Hissed 'ss' are retained as the exception. */
/*                                                                            */
/* 8. SYLLABIC JUNCTIONS & DIAERESIS OPERATORS                                */
/* - The diaeresis (¨) signals a "Junction" where a vowel team is broken or   */
/*   a phonetic lane shift occurs due to rhythmic decay or heritage.          */
/* - MODAL USE: In "Fidelity" mode, it ensures full phonetic fidelity. In     */
/*   "Approximation" mode, it is omitted for frictionless heritage typing.    */
/* - JUNCTION BREAKS: Placed on the second vowel to separate a root from a    */
/*   suffix (doïng, beïng, lowër) or to distinguish from a protected team     */
/*   (lowër vs flower). This preserves root-word recognition.                 */
/*                                                                            */

#define C              "([b-df-hj-np-tv-z])"
#define CC             "([b-df-hj-np-tv-z]r?|chr?|kl|qu|shr?|thr?)"
#define SYLLABLE       "([b-df-hj-np-tv-z]*[aeiouy]*[b-df-hj-np-tv-z]*)"
#define PREFIX_L2      "re|un|in|im|en|em|ad|ex|de|ko|on|"
#define PREFIX_L3      "any|dis|pre|mid|mis|pro|kon|sub|non|tri|uni|"
#define PREFIX_L4      "[a-z][a-z][a-z][a-z]+"
#define BEGIN          "__(" PREFIX_L2 PREFIX_L3 PREFIX_L4 ")?"
#define END_E          "(es|ing|ed|er|es|able|y|ely|d|r|s)?e?__"
#define PREFIX         "\\b(" PREFIX_L2 PREFIX_L3 PREFIX_L4 ")?"
#define SUFFIX         "(s|ing|ed|er|ers|ering|ered|able|y|ful|ist)?\\b"
#define SUFFIX_E       "(s|ing|d|r|s|able|y|ely|ful)?\\b"
#define ROMANCE_SIGNAL "(v|c|g|z)"
#define MAX_STR        32768

void subst(char *text, const char *pattern, const char *replace) {
	regex_t reg;
	regmatch_t matches[10];
	char buffer[MAX_STR];
	char *src = text;
	int pos = 0;

	if (regcomp(&reg, pattern, REG_EXTENDED) != 0) return;

	buffer[0] = '\0';
	while (regexec(&reg, src, 10, matches, 0) == 0) {
		int i;
		int prefix_len = matches[0].rm_so;
		memcpy(buffer + pos, src, prefix_len);
		pos += prefix_len;

		for (i = 0; replace[i] != '\0'; i++) {
			if (replace[i] == '\\' && replace[i+1] >= '1' && replace[i+1] <= '9') {
				int n = replace[++i] - '0';
				int match_len = matches[n].rm_eo - matches[n].rm_so;
				memcpy(buffer + pos, src + matches[n].rm_so, match_len);
				pos += match_len;
			} else {
				buffer[pos++] = replace[i];
			}
		}
		src += matches[0].rm_eo;
	}
	strcpy(buffer + pos, src);
	strcpy(text, buffer);
	regfree(&reg);
}


/* Translate English 1.0 (general lexicon) to 2.0.                        */
/*                                                                        */
/* Initial scope of this translator is the top 2000 words below.          */
/* Wider scope will be considered once top 2000 words are fully verified. */
/*                                                                        */
int main(int argc, char *args[]) {
	int vflag = argc > 1 && strcmp(args[1], "-v") == 0 && (++args,--argc);
	int eflag = argc > 1 && strcmp(args[1], "-e") == 0 && (++args,--argc);
	char text[MAX_STR];
	char *arg = argc > 1 ? args[1] :
	"the        I          to         and        a          of         was        he        |\n"
	"you        it         in         her        she        that       my         his       |\n"
	"me         on         with       at         as         had        for        but       |\n"
	"him        said       be         up         out        look       so         have      |\n"
	"what       not        just       like       go         they       is         this      |\n"
	"from       all        we         were       back       do         one        about     |\n"
	"know       if         when       get        then       into       would      no        |\n"
	"there      could      ask        down       time       want       eye        them      |\n"
	"over       your       are        or         been       now        an         by        |\n"
	"think      see        hand       say        how        around     head       did       |\n"
	"well       before     off        who        more       even       turn       come      |\n"
	"smile      way        really     can        face       other      some       right     |\n"
	"their      only       walk       make       got        try        something  room      |\n"
	"again      thing      after      still      thought    door       here       too       |\n"
	"little     because    why        away       let        take       two        start     |\n"
	"good       where      never      through    day        much       tell       girl      |\n"
	"feel       oh         call       talk       will       long       than       us        |\n"
	"made       friend     knew       open       need       first      which      people    |\n"
	"went       sure       seem       stop       voice      very       felt       took      |\n"
	"our        pull       laugh      man        okay       close      any        came      |\n"
	"told       love       watch      arm        anything   though     put        left      |\n"
	"work       guy        hair       next       yeah       while      mean       home      |\n"
	"few        saw        place      school     help       wait       late       year      |\n"
	"house      happen     last       always     move       old        night      nod       |\n"
	"life       give       sit        stare      sat        should     moment     another   |\n"
	"behind     side       sound      once       find       toward     boy        ever      |\n"
	"nothing    front      mother     name       am         since      reply      myself    |\n"
	"leave      bed        new        car        use        mind       maybe      has       |\n"
	"heard      answer     minute     yes        until      both       found      end       |\n"
	"small      word       someone    same       enough     began      run        bit       |\n"
	"sigh       each       those      almost     against    everything most       thank     |\n"
	"mom        better     play       own        every      hard       remember   three     |\n"
	"stood      live       stand      second     sorry      keep       finally    point     |\n"
	"gave       already    actually   probably   himself    big        everyone   guess     |\n"
	"lot        step       hey        hear       light      quickly    dad        kiss      |\n"
	"black      pick       else       soon       shoulder   table      best       without   |\n"
	"notice     stay       care       phone      reach      realize    follow     decide    |\n"
	"kind       grab       show       inside     suddenly   father     rest       herself   |\n"
	"grin       hour       hope       also       body       might      floor      its       |\n"
	"continue   ran        across     hold       cry        half       pretty     great     |\n"
	"course     mouth      class      kid        miss       wonder     morning    least     |\n"
	"nice       dark       slowly     done       change     together   yet        question  |\n"
	"anyway     bad        blue       believe    week       God        lip        Mr.       |\n"
	"sleep      fine       family     many       worry      roll       parent     under     |\n"
	"surprise   water      onto       glance     wall       between    seen       read      |\n"
	"window     idea       white      push       feet       must       such       seat      |\n"
	"set        please     red        brother    these      whole      lean       part      |\n"
	"person     slightly   pass       shook      fact       wrong      gone       far       |\n"
	"hit        finger     quite      hate       meet       finish     heart      book      |\n"
	"past       kill       reason     anyone     figure     top        along      world     |\n"
	"high       shirt      does       today      young      held       outside    listen    |\n"
	"whisper    happy      ground     deep       drop       shrug      dress      fell      |\n"
	"yell       breath     air        tear       sister     chair      kitchen    matter    |\n"
	"hurt       fall       wear       woman      eat        lie        hell       suppose   |\n"
	"cover      couple     large      either     five       leg        jump       die       |\n"
	"return     able       bag        alone      shut       stuff      short      ready     |\n"
	"understand kept       plan       raise      street     different  problem    break     |\n"
	"line       early      cut        cold       paper      scream     instead    stupid    |\n"
	"silence    tree       caught     ear        food       full       four       cause     |\n"
	"fuck       explain    expect     fight      exactly    sort       completely men       |\n"
	"dance      met        story      whatever   build      speak      glass      pain      |\n"
	"check      glare      corner     Mrs.       chest      hot        rather     month     |\n"
	"real       touch      park       bring      drink      ago        force      fast      |\n"
	"lost       attention  wish       mark       wave       shout      fill       begin     |\n"
	"baby       interest   money      fun        green      however    cheek      mine      |\n"
	"clear      brown      forward    near       picture    may        cool       drive     |\n"
	"hug        shake      sense      alright    dream      hang       clothes    act       |\n"
	"become     manage     meant      game       ignore     stair      taken      party     |\n"
	"add        sometimes  job        ten        shot       date       quiet      gaze      |\n"
	"group      loud       straight   dead       neck       beside     pause      number    |\n"
	"conversation chance   rose       quietly    town       blood      color      desk      |\n"
	"dinner     hall       horse      music      brought    piece      anymore    beautiful |\n"
	"order      fire       office     true       although   warm       easy       enter     |\n"
	"perfect    mutter     softly     cross      shock      smirk      damn       soft      |\n"
	"stomach    snap       spoke      tire       box        catch      skin       teacher   |\n"
	"middle     note       yourself   lunch      tomorrow   breathe    clean      except    |\n"
	"appear     lock       knock      bathroom   movie      agree      offer      kick      |\n"
	"form       confuse    lay        less       calm       slip       sign       dog       |\n"
	"lift       immediately arrive    deal       tonight    usually    case       frown     |\n"
	"shop       scare      promise    mum        couch      pay        state      shit      |\n"
	"wrap       pocket     hello      free       huge       ride       bother     land      |\n"
	"known      especially expression carry      ring       spot       allow      several   |\n"
	"during     empty      lady       eyebrow    strange    coffee     road       threw     |\n"
	"wide       bus        forget     gotten     smell      fear       press      boyfriend |\n"
	"blonde     throw      round      sun        tall       glad       age        write     |\n"
	"upon       hide       became     crowd      rain       save       trouble    annoy     |\n"
	"nose       weird      death      beat       tone       trip       six        control   |\n"
	"nearly     consider   gonna      join       learn      above      hi         obviously |\n"
	"entire     direction  foot       angry      power      strong     quick      doctor    |\n"
	"edge       song       asleep     twenty     barely     remain     child      enjoy     |\n"
	"gun        slow       city       broke      key        lead       throat     normal    |\n"
	"somewhere  wake       pair       sky        funny      business   student    giggle    |\n"
	"bright     admit      jeans      given      children   store      sweet      low       |\n"
	"climb      rub        apartment  knee       shoe       attack     bedroom    joke      |\n"
	"spent      situation  stuck      gently     possible   cell       mention    silent    |\n"
	"definitely rush       hung       brush      perhaps    groan      ass        rock      |\n"
	"card       lose       blush      besides    crazy      type       bore       afraid    |\n"
	"chase      respond    marry      remind     pack       daughter   serious    girlfriend|\n"
	"mad        somehow    buy        sent       tight      simply     trust      imagine   |\n"
	"wind       chuckle    bar        pink       shove      ball       sight      drag      |\n"
	"human      truth      share      area       concern    team       escape     mumble    |\n"
	"often      search     apparently attempt    son        within     band       cute      |\n"
	"led        memory     anger      fly        paint      bottle     busy       comment   |\n"
	"exclaim    avoid      grow       grey       mirror     gasp       hallway    dear      |\n"
	"star       sick       cat        counter    interrupt  none       blink      spend     |\n"
	"usual      worse      locker     important  favorite   grip       TV         ice       |\n"
	"pretend    settle     amaze      pop        disappear  carefully  train      stick     |\n"
	"guard      teeth      flash      uncle      send       doubt      visit      nervous   |\n"
	"excite     approach   excuse     fit        noise      study      letter     police    |\n"
	"eventually burn       field      hospital   tie        summer     huh        shift     |\n"
	"self       hurry      greet      wife       position   wipe       heavy      slam      |\n"
	"broken     complete   space      brain      tiny       pants      ah         punch     |\n"
	"shower     tongue     afternoon  seriously  cup        further    race       recognize |\n"
	"computer   rang       safe       jacket     bottom     hundred    relax      sudden    |\n"
	"wow        college    flip       mood       track      crack      block      handle    |\n"
	"themselves drove      seven      struggle   whether    ahead      sad        dry       |\n"
	"women      focus      repeat     thick      relationship jerk     present    suck      |\n"
	"bell       surround   evening    bite       single     fault      shadow     wood      |\n"
	"easily     woke       smoke      draw       suggest    wet        accept     third     |\n"
	"totally    wore       breakfast  trail      animal     warn       aunt       sir       |\n"
	"piss       burst      match      fix        practically odd       wash       sing      |\n"
	"inch       size       secret     clock      company    view       suit       forever   |\n"
	"familiar   forehead   shoot      grew       stretch    pound      despite    response  |\n"
	"center     curl       slight     toss       beneath    fist       welcome    laughter  |\n"
	"angel      Christmas  main       simple     neither    distance   comfort    upset     |\n"
	"assume     eight      gather     lucky      fade       Ms.        coat       special   |\n"
	"awkward    certain    plate      darkness   practice   obvious    grade      cream     |\n"
	"choice     hardly     pale       thin       button     chocolate  refuse     slid      |\n"
	"pillow     thirty     count      honestly   poor       motion     storm      lightly   |\n"
	"nobody     experience path       period     dare       demand     comfortable clearly  |\n"
	"silver     peer       birthday   disgust    embarrass  bought     test       lap       |\n"
	"bet        loudly     driver     murmur     taste      perfectly  squeeze    board     |\n"
	"worth      fold       spread     crap       emotion    subject    pour       laid      |\n"
	"lower      mile       yea        page       pile       snow       message    English   |\n"
	"scene      sink       fail       forgot     hole       silently   heat       weekend   |\n"
	"drew       guitar     sweat      unless     cloud      waist      slap       argue     |\n"
	"grass      idiot      screen     yesterday  swear      twin       instantly  apart     |\n"
	"narrow     opposite   blow       wrist      earth      action     circle     forgotten |\n"
	"list       closet     drunk      shape      yellow     twist      weight     smart     |\n"
	"treat      pool       prepare    awake      certainly  tease      contact    slide     |\n"
	"wonderful  bitch      reveal     swing      truck      anywhere   flower     upstairs  |\n"
	"hers       itself     wander     downstairs football   possibly   rip        forest    |\n"
	"mostly     bloody     church     gay        stone      husband    sex        trick     |\n"
	"yours      growl      club       Friday     stage      include    sip        invite    |\n"
	"sharp      convince   sheet      absolutely orange     relief     apologize  art       |\n"
	"remove     crash      van        curse      alive      blanket    receive    tip       |\n"
	"rise       tightly    waste      bowl       fallen     river      mama       pace      |\n"
	"honey      swallow    king       camera     deserve    dirty      chin       doorway   |\n"
	"image      cookie     homework   hat        luck       aside      information fifteen  |\n"
	"fair       player     monster    gate       win        below      ceiling    click     |\n"
	"cook       travel     fish       lit        nervously  towel      shiver     final     |\n"
	"horrible   station    camp       hungry     thousand   evil       rich       war       |\n"
	"involve    jaw        uncomfortable directly level     double     nine       creature  |\n"
	"glow       somewhat   blame      entrance   hip        fresh      hiss       normally  |\n"
	"tap        machine    ruin       bear       rule       till       cock       stumble   |\n"
	"complain   everybody  truly      nurse      speed      hmm        panic      smooth    |\n"
	"weak       good-bye   extra      gesture    scowl      beer       release    country   |\n"
	"officer    careful    create     hill       snort      flew       heel       brow      |\n"
	"charge     flat       plus       switch     whenever   drift      metal      discover  |\n"
	"wheel      skirt      pat        ate        tea        hotel      sob        future    |\n"
	"record     boot       likely     cheer      gold       prove      ha         twice     |\n"
	"aware      lack       princess   bench      cousin     detail     amount     bird      |\n"
	"backward   crush      cigarette  faint      belong     stranger   beach      load      |\n"
	"everywhere scratch    history    restaurant event      extremely  widen      clutch    |\n"
	"due        tug        beyond     happily    mistake    palm       amuse      guest     |\n"
	"Saturday   wooden     worst      exit       plastic    reality    wince      announce  |\n"
	"gotta      slept      member     choose     Dr.        swim       alarm      crawl     |\n"
	"dollar     knife      magic      paid       pizza      purse      gift       chicken   |\n"
	"plane      choke      screw      protest    base       drug       introduce  sleeve    |\n"
	"movement   loose      bare       wanna      difficult  frame      spin       fake      |\n"
	"pen        understood nor        unfortunately written  decision  beg        heavily   |\n"
	"insist     soul       random     sport      male       urge       million    yawn      |\n"
	"backpack   judge      startle    bunch      stream     muscle     yard       accident  |\n"
	"dragon     sentence   fool       torn       bow        echo       mix        bury      |\n"
	"system     dirt       spirit     leaf       protect    row        forth      purple    |\n"
	"bang       curious    nearby     nowhere    collapse   hop        proud      wing      |\n"
	"destroy    sea        separate   silly      wound      honest     battle     born      |\n"
	"cough      mountain   split      square     underneath bike       process    somebody  |\n"
	"classroom  presence   whose      grown      hidden     serve      female     garden    |\n"
	"meal       unable     elbow      support    bridge     reaction   skip       wild      |\n"
	"angrily    effect     threaten   basically  smack      stroke     flow       moan      |\n"
	"plant      impossible bruise     disappoint energy     relieve    confusion  wedding   |\n"
	"fat        bill       dude       address    cast       naked      toy        math      |\n"
	"personal   ship       spun       chat       pray       whip       grasp      float     |\n"
	"fully      gorgeous   indeed     nail       vision     innocent   friendly   jealous   |\n"
	"swung      flame      dorm       driveway   spill      gang       murder     respect   |\n"
	"bent       tail       inform     lesson     whine      clench     excitement library   |\n"
	"lord       surface    dust       dump       feature    object     weapon     calmly    |\n"
	"hesitate   hint       law        magazine   among      boss       file       leather   |\n"
	"result     thrown     toe        terrible   local      project    won        radio     |\n"
	"regret     grumble    otherwise  ridiculous CD         lovely     mock       effort    |\n"
	"fan        nerve      report     stall      elevator   mate       bastard    grunt     |\n"
	"rope       entirely   frighten   shade      strength   bone       exchange   flight    |\n"
	"Monday     partner    plain      shine      cafeteria  beam       exist      porch     |\n"
	"queen      squeal     faith      pierce     remark     content    ease       flick     |\n"
	"mall       cannot     carpet     length     replace    duck       bump       common    |\n"
	"style      tan        cake       court      previous   balance    bank       blind     |\n"
	"dangerous  particular sell       wrote      distract   melt       popular    social    |\n"
	"teach      appearance correct    lake       public     sarcastically guilty  kinda     |\n"
	"shall      television boat       firmly     tent       thumb      manner     flush     |\n"
	"roof       schedule   dine       weather    casually   moon       difference butt      |\n"
	"charm      feed       frustration gentle    hook       bounce     particularly pleasure|\n"
	"sneak      leader     rage       shriek     suffer     Sunday     argument   pregnant  |\n"
	"discuss    statement  ticket     dig        doll       chill      fence      horror    |\n"
	"built      cop        security   sidewalk   breast     curtain    whom       fifty     |\n"
	"giant      milk       recall     term       footstep   stun       tuck       clothing  |\n"
	"lick       joy        ugly       hopefully  soldier    plead      struck     trap      |\n"
	"opinion    plenty     tank       breeze     awesome    desire     roommate   halfway   |\n"
	"opportunity outfit    rough      beauty     chose      snake      tape       badly     |\n"
	"cheat      daddy      roar       describe   desperately height    thigh      tilt      |\n"
	"deeply     friendship winter     witch      worn       condition  enemy      golden    |\n"
	"sofa       master     rude       throughout assure     damage     natural    steal     |\n"
	"belt       cage       claim      nightmare  prefer     purpose    merely     pin       |\n"
	"French     sadly      uniform    branch     direct     hunter     juice      character |\n"
	"pure       stain      various    gain       soak       lately     pitch      accent    |\n"
	"tremble    cabin      chew       physical   puzzle     explode    steady     pet       |\n"
	"sake       compare    principal  scan       forty      impress    mentally   react     |\n"
	"sandwich   shy        twelve     whilst     bullet     challenge  command    examine   |\n"
	"film       appreciate tense      blank      blew       fought     gym        passenger |\n"
	"teenager   dish       drawn      scary      unlike     straighten strain     tune      |\n"
	"constantly famous     marriage   bound      fancy      issue      warmth     awhile    |\n"
	"collect    concentrate copy      disbelief  tighten    determine  favor      mental    |\n"
	"bush       forgive    aim        embrace    fairly     froze      insult     option    |\n"
	"post       resist     spoken     apple      general    instant    jeep       emerge    |\n"
	"neighbor   pressure   service    shuffle    briefly    notebook   peace      string    |\n"
	"wine       dash       gut        stress     connect    language   private    spring    |\n"
	"chip       puppy      ache       desperate  habit      necessary  nope       pencil    |\n"
	"satisfy    deny       mommy      attitude   dial       painful    display    frustrate |\n"
	"tend       exact      powerful   nature     photo      total      video      egg       |\n"
	"occur      anybody    corridor   gulp       trace      whoever    brief      exhaust   |\n"
	"pout       terrify    chapter    insane     spell      surely     tray       alcohol   |\n"
	"chain      fashion    garage     inquire    candy      similar    bark       flirt     |\n"
	"pathetic   supply     tower      engine     frozen     map        toilet     background|\n"
	"shudder    spider     adult      cheap      clue       hazel      irritate   sand      |\n"
	"quarter    spare      American   rid        spat       pot        awful      bleed     |\n"
	"fate       jog        strike     grimace    holiday    whistle    agreement  dull      |\n"
	"expensive  snatch     sometime   ability    campus     collar     disturb    flicker   |\n"
	"proceed    recently   risk       skill      topic      defense    fry        luckily   |\n"
	"retort     captain    eaten      glove      mid        owner      cheese     yank      |\n"
	"afterward  closely    coach      feather    handsome   New York   pity       signal    |\n"
	"sniff      strap      contain    survive    sweater    west       drawer     leap      |\n"
	"major      peek       suspect    tour       freeze     heaven     mask       surprisingly|\n"
	"abruptly   begun      customer   pad        design     flop       pride      yep       |\n"
	"interview  makeup     blast      prince     rode       bubble     rent       teen      |\n"
	"\n"
	"the love of liberty and the hope for a better life must come to restore happiness.\n"
	"our brothers and mothers have now become the some who gave all for the many.\n"
	"the judge in prague must prove that justice is not a dove that flies above our reach.\n"
	"in towne, a dozen more women stood in two straight lines at the height of noon.\n"
	"none should shove aside the truth or mistranslate the dialogues of the divine.\n"
	"we have purified honey and money for the monk to dine. the league and vogue are here.\n"
	"the fatigue of the plague was heavy. he bought bread while coughing near the trough.\n"
	"the journey in the ravine was long. they fought for the rough and sought the light.\n"
	"the quick brown fox jumped over the lazy dog. keep me updated on the marketing plan.\n"
	"reconcile the compiler output with stockpiled data on the mobile phone over there.\n";

	strcpy(text, arg);
	setlocale(LC_ALL, "en_US.UTF-8");

	/* Consonant mandates streamlined: 'c' and 's' */
	subst(text, PREFIX "school"     SUFFIX, "\\1skool\\2"); /* (al)together   */
	subst(text, "c([^eiyhk]|\\b)",  "k\\1");
	subst(text, "kc([^eiyhk]|\\b)", "kk\\1");
	subst(text, "([aeiou])s([aeiou])", "\\1z\\2");  /* note: is, was, has, does, as are unchanged */

	/* Consonant mandates streamlined: 'g' */
	subst(text, PREFIX "g(et|ive?|ir[ld]|ift|ig)" SUFFIX, "\\1g__\\2\\3");     /* get, give, gig */
	subst(text, PREFIX "(ea|ti|trig)ger"          SUFFIX, "\\1\\2ger__\\3");   /* eager, tiger   */
	subst(text, PREFIX "beg(in|an)"               SUFFIX, "\\1beg__\\2\\3");   /* begin/began    */
	subst(text, PREFIX "together"                 SUFFIX, "\\1tog__ether\\2"); /* (al)together   */
	subst(text, "\\bgi([bdglz]{2}|ld)[a-z]*"      SUFFIX, "g__i\\1\\2");       /* giddy, giggle  */
	subst(text, "\\bge([ea]|ck|ys)[a-z]*"         SUFFIX, "g__e\\1\\2");       /* gecko, g+LongE */
	subst(text, "\\b([^g][a-z]*)nger"             SUFFIX, "\\1ng__er\\2");     /* anger, ^ginger */
	subst(text, "g([eiy])", "j\\1");
	subst(text, "g__", "g");

	/* Protection for words that look like Long Vowel roots but are short */
	subst(text, "\\b(we|the)re\\b", "__\\1re__");
	subst(text, PREFIX "said\\b", "__saïd__");                  /* direct phonetic fix */
	subst(text, PREFIX "says\\b", "__sayz__");

	subst(text, PREFIX "(hav|giv|liv|on)e"        SUFFIX_E, "__\\1\\2e\\3__");  /* prevent haeve geive */
	subst(text, PREFIX "(man|an|ci|ver|bod)y"     SUFFIX_E, "__\\1\\2y\\3__");  /* any city very body  */
	subst(text, PREFIX "(pr|m)ove"                SUFFIX_E, "__\\1\\2oove\\3__");
	subst(text, PREFIX "(d|l|ab|m|sh)ove"         SUFFIX_E, "__\\1\\2ove\\3__");
	subst(text, PREFIX "(s|k|bek)ome"             SUFFIX_E, "__\\1\\2ome\\3__");
	subst(text, PREFIX "(non|don|arg|agu)e"       SUFFIX_E, "__\\1\\2e\\3__");
	subst(text, PREFIX "(o|bo|mo|bro|smo)ther"    SUFFIX, "__\\1\\2ther\\3__");
	subst(text, PREFIX "(kov|diskov|nev)er"       SUFFIX, "__\\1\\2er\\3__");
	subst(text, PREFIX "journ(ey|al)"             SUFFIX, "__\\1joürn\\2\\3__");
	subst(text, PREFIX "do(zen)\\b"               SUFFIX, "__\\1du\\2\\3__");
	subst(text, PREFIX "wo(man|men)\\b"           SUFFIX, "__\\1wu\\2\\3__");
	subst(text, PREFIX "monk\\b",  "__munk__");
	subst(text, PREFIX "won\\b",   "__wun__");

	/* Protect -age (damage, courage) except long (stage, cage, rage) */
	/* Protect -ate: (privat), process long (translate, rotate - mostly verbs) */
	subst(text, "\\b([a-z]*)" "a(g|t)e"           SUFFIX_E, "__\\1a\\2e\\3__");
	subst(text, BEGIN "(st|k|r|p|w|g)ag"          END_E, "\\1\\2aeg\\3");
	subst(text, BEGIN "(cre|dict|isol|st|rot)at"  END_E, "\\1\\2aet\\3");
	subst(text, BEGIN "(loc|migr|narr|rel)at"     END_E, "\\1\\2aet\\3");
	subst(text, BEGIN "(transl|upd|vibr)at"       END_E, "\\1\\2aet\\3");

	/* Protect -ile: dialect-Swings between Long I & schwa except atomic (pile, file family) */
	subst(text, "\\b([a-z]*[^aiou])" "i(l)e"      SUFFIX_E, "__\\1i\\2e\\3__");
	subst(text, "__([a-z]*)(p|ex|f|konc)il"       END_E, "\\1\\2iyl\\3");  /* add crocodile? */
	subst(text, BEGIN "(b|sm|wh)il"               END_E, "\\1\\2iyl\\3");

	/* Protect -ine: mainly Swing /ɪ/~/i/ except atomic & derivatives (-line, -fine, -pine, etc) */
	subst(text, "\\b([a-z]*[^aiou])" "i(n)e"      SUFFIX_E, "__\\1i\\2e\\3__");
	subst(text, "__([a-z]*)(b|f|l|n|p|sh|w|v)in"  END_E, "\\1\\2iyn\\3");  /* derivatives of core atomics */
	subst(text, BEGIN "(br|equ?|shr|sw|th|wh)in"  END_E, "\\1\\2iyn\\3");
	subst(text, BEGIN "(bronz|carm|underm|d)in"   END_E, "\\1\\2iyn\\3");
	subst(text, BEGIN "(mascul|femin|discipl)in"  END_E, "\\1\\2inë\\3");  /* exceptions to core atomics */

	/* Protect -ice/-ive: mainly Swing /ɪ/~/i/ except atomic & derivatives (price/[^r]vice) */
	subst(text, "\\b([a-z]*[^aiou])" "i(c|v)e"    SUFFIX_E, "__\\1i\\2e\\3__");
	subst(text, BEGIN "(d|l|n|pr|r|sl|tr|v)ic"    END_E, "\\1\\2iyc\\3");
	subst(text, BEGIN "(ent|spl|suff|tw|thr)ic"   END_E, "\\1\\2iyc\\3");
	subst(text, BEGIN "(conc|sacrif)ic"           END_E, "\\1\\2iyc\\3");
	subst(text, BEGIN "(al|ch|d|dr|f|h|j|l)iv"    END_E, "\\1\\2iyv\\3");
	subst(text, BEGIN "(arch|arr|conn|contr)iv"   END_E, "\\1\\2iyv\\3");
	subst(text, BEGIN "(der|depr|str|surv)iv "    END_E, "\\1\\2iyv\\3");

	/* Protect -ite: (favorite, marguerite, -finite, opposite, requisite, etc) */
	subst(text, PREFIX "([a-z]*)finite"           SUFFIX_E, "__\\1\\2finitë\\3__");
	subst(text, PREFIX "([a-z]*[io])site"         SUFFIX_E, "__\\1\\2sitë\\3__");
	subst(text, PREFIX "(hypocr|favour|resp)ite"  SUFFIX_E, "__\\1\\2itë\\3__");
	subst(text, PREFIX "(el|mesqu?|pet|su)ite"    SUFFIX_E, "__\\1\\2etë\\3__");  /* French Long E */
	subst(text, PREFIX "([a-z]*)uerite"           SUFFIX_E, "__\\1\\2ueritë\\3__");

	/* Protect -ure: (-zure/-ture & failure always decayed) */
	subst(text, "\\b([a-z]*)(j|t|z|ch|sh|sz)ure"  SUFFIX_E, "__\\1\\2urë\\3__");
	subst(text, "\\b([a-z]*)(fail|press)ure"      SUFFIX_E, "__\\1\\2urë\\3__");

	/* Protect -are, -ore: r-controlled, never Magic-E */
	subst(text, "\\b([a-z]*)ore"                  SUFFIX_E, "__\\1ore\\2__");
	subst(text, "\\b([a-z]*)are"                  SUFFIX_E, "__\\1are\\2__");

	/* Protect selected -ose/-ise (purpose, promise) */
	subst(text, PREFIX "(purpo|ani|morti)se"      SUFFIX_E, "__\\1\\2se\\3__");
	subst(text, PREFIX "(pract|prom|treat)ise"    SUFFIX_E, "__\\1\\2ise\\3__");

	/* Protect -gue: (intrigue, fatigue, tongue), except long (league, vague, rogue) */
	subst(text, "\\b([a-z]*)" C "([e]?[aio])gue"  SUFFIX_E, "__\\1\\2\\3ge\\4__");
	subst(text, BEGIN "(pr)ag"                    END_E, "\\1\\2ahg\\3");
	subst(text, BEGIN "(v|pl)ag"                  END_E, "\\1\\2aeg\\3");
	subst(text, BEGIN "(v|r)og"                   END_E, "\\1\\2oeg\\3");     /* Long O: rogue, vogue */
	subst(text, BEGIN "([a-z]*[^aeiou])og"        END_E, "__\\1\\2og\\3__");  /* Short O otherwise */
	subst(text, BEGIN "([a-z]*[^aeiou])ig"        END_E, "\\1\\2iyg\\3");     /* Swing I */
	subst(text, BEGIN "([a-z]*)eag"               END_E, "\\1\\2eag\\3");	  /* Long E, no swing */
	subst(text, PREFIX "(t)ongue"                 SUFFIX_E, "__\\1\\2unge\\3__");

	/* Convert -ique to -iyqe */
	subst(text, PREFIX "(b)outique"               SUFFIX_E, "__\\1\\2uetiyq\\3__");
	subst(text, PREFIX "([a-z]*[^aeiou])aque"     SUFFIX_E, "__\\1\\2aeq\\3__");
	subst(text, PREFIX "([a-z]*[^aeiou])ique"     SUFFIX_E, "__\\1\\2iyq\\3__");
	subst(text, PREFIX "([a-z]*[^aeiou])oque"     SUFFIX_E, "__\\1\\2oeq\\3__");

	/* Convert -ind to -iynd: note wind => wind (noun) or wiynd (verb) */
	subst(text, PREFIX "([bfhkmr]|rew|unw)ind"    SUFFIX, "__\\1\\2iynd\\3__");

	/* Protect all word initial [gq]u, mark silent initial u's (eg. built) */
	subst(text, PREFIX "([gq])u(a-z)*\\b", "__\\1\\2u\\3");  /* don't protect ending */
	subst(text, PREFIX "built", "__\\1buïlt__");

	/* Handles roots that use terminal E as a Long I signal */
	subst(text, "\\b(b|m|wh)y\\b", "__\\1y__");                 /* Atoms: by, my, why */
    subst(text, "\\b(d|l|p|t|v)ie"               SUFFIX, "__\\1\\2ie\\3__");  /* die -> die   */
    subst(text, PREFIX "(fl|sk|sl|n)y"           SUFFIX, "__\\1\\2igh\\3__"); /* fly -> fligh */
    subst(text, PREFIX "(tr|kr|fr|dr|wr|sh|wr)y" SUFFIX, "__\\1\\2y\\3__");   /* try -> try   */
    subst(text, PREFIX "(tr|kr|fr|dr|sh)ied\\b", "__\\1\\2ied__");            /* tried        */
    subst(text, PREFIX "(tr|kr|fr|dr|sh)ies\\b", "__\\1\\2ies__");            /* tries        */
    subst(text, PREFIX "(fl|sk|sl)ies\\b", "__\\1\\2ighs__");                 /* flighs       */

	subst(text, PREFIX "([a-z]+)ify"             SUFFIX, "__\\1\\2ify\\3__"); /* purify       */
	subst(text, PREFIX "([a-z]+)ified\\b", "__\\1\\2ified\\3__");             /* purified     */
	subst(text, PREFIX "([a-z]+)ifies\\b", "__\\1\\2ifies\\3__");             /* purifies     */
	subst(text, PREFIX "(appl|den|rel|suppl|impl|kompl|def|all)ÿ" SUFFIX, "__\1\2y\3__");

	/* Convert -ey Long A to -ay and protect Scribal O -ey words */
	subst(text, PREFIX "(mon|hon|donk|monk)ey"   SUFFIX, "__\\1\\2ey\\3__"); /* honey, money */
	subst(text, PREFIX "(ob|konv|surv)ey"        SUFFIX, "__\\1\\2ay\\3__");      /* obey -> obay */
	subst(text, PREFIX "(h|sl)eight"             SUFFIX, "__\\1\\2eïght\\3__");    /* height -> heïght */

	/* Now that stressed words are locked in __, we can safely swing the rest.        */
	subst(text, "\\b([a-z]*)" "([a-df-z]+)y"     SUFFIX, "\\1\\2y\\3");     /* happy  */
	subst(text, "\\b([a-z]*)" "([a-z]+)ie(s|d|r)\\b",   "\\1\\2ië\\3"); /* citiës */

	/* Convert wash/swap to 'o' but work/word/world are Scribal O-Glide markers */
	subst(text, PREFIX "(w)ash" SUFFIX, "\\1\\2osh\\3");       /* wash -> wosh  */
	subst(text, PREFIX "(sw)ap" SUFFIX, "\\1\\2op\\3");        /* swap -> swop  */

	/* Evicts Germanic roots from the Romance 'er' and 'ur' markers             */
	subst(text, "\\b(ch)urch" SUFFIX, "chirch\\1");          /* church->chirch  */

	/* Convert -ow- diphthong to -owe-/-owne (note: flower, however, power = owe) */
	subst(text, PREFIX "(c|br|pl|h|n|v|w)owe?"   SUFFIX_E, "__\\1\\2owe\\3__");   /* how  -> howe  */
	subst(text, PREFIX "(all|eyebr)owe?"         SUFFIX_E, "__\\1\\2owe\\3__");
	subst(text, PREFIX "(br|cl|cr|d|g)owne?"     SUFFIX_E, "__\\1\\2owne\\3__");  /* town -> towne */
	subst(text, PREFIX "(dr|fr|ren|t)owne?"      SUFFIX_E, "__\\1\\2owne\\3__");
	subst(text, PREFIX "(b)rowse?"               SUFFIX_E, "__\\1\\2owese\\3__"); /* browse -> browese */
	subst(text, PREFIX "(cr|r)owd"               SUFFIX, "__\\1\\2owed\\3__");  /* rowd -> rowed */
	subst(text, PREFIX "(h|gr|pr|sc|)owl"        SUFFIX, "__\\1\\2owel\\3__");  /* howl -> howel */
	subst(text, PREFIX "(c)oward"                SUFFIX, "__\\1\\2oweard\\3__");
	subst(text, PREFIX "(d)ownload"              SUFFIX, "__\\1\\2owneload\\3__");

	/* Convert -ough outliers to their correct lanes */
	subst(text, PREFIX "laugh"                   SUFFIX, "__\\1laghf\\2__");
	subst(text, PREFIX "through"                 SUFFIX, "__\\1thru\\2__");
	subst(text, PREFIX "plough"                  SUFFIX, "__\\1plowe\\2__");
	subst(text, PREFIX "(al)?though"             SUFFIX, "__\\1\\2though\\3__");
	subst(text, PREFIX "(bor|d|furl)ough"        SUFFIX, "__\\1\\2ough\\3__");
	subst(text, PREFIX "(b|br|f|n|s|th|wr)ought" SUFFIX, "__\\1\\2aught\\3__");
	subst(text, PREFIX "(en|k|r|t|sl|tr)ough"    SUFFIX, "__\\1\\2ughf\\3__");
	subst(text, PREFIX "(k)ough"                 SUFFIX, "__\\1\\2aughf\\3__");

	/* TODO: Convert -ou- outliers to their correct lanes */
	//	subst(text, PREFIX "(sh|b)oulder" SUFFIX, "\\1\\2oelder\\3");
	//	subst(text, PREFIX "mould" SUFFIX, "\\1moeld\\2");  // also poultry
	//	subst(text, PREFIX "(cousin|touch|young)" SUFFIX, "\\1\\2u\\3");
	//  TODO: souvenir, mousse

	subst(text, PREFIX "(r)ouge"        SUFFIX, "__\\1\\2uege\\3__");
	subst(text, PREFIX "(w)ound"        SUFFIX, "__\\1\\2uend\\3__");
	subst(text, PREFIX "(g|gr|s)oup"    SUFFIX, "__\\1\\2uep\\3__");
	subst(text, PREFIX "(c)oupon"       SUFFIX, "__\\1\\2uepon\\3__");
	subst(text, PREFIX "(t)our"         SUFFIX, "__\\1\\2uer\\3__");
	subst(text, PREFIX "(r)oute"        SUFFIX, "__\\1\\2uete\\3__");
	subst(text, PREFIX "(y)ou(th)?"     SUFFIX, "__\\1\\2ue\\3\\4__");
	subst(text, PREFIX "(cr)outon"      SUFFIX, "__\\1\\2ueton\\3__");

#define UNSTRESSED    "(\\ba|be|de|du|re|un|up|in|en|ex|pre|kon|kom|dis|mis|sub|per|pro|inter|over|under|__|\\b)"
#define SUFFIX_SAFE   "(s|ful|able|ous|ly|ment|ness)?"
#define SUFFIX_UNSAFE "(ing|ish|ion|ity|ed|er|est|ent|y)"

	if (!eflag) {
		/* use => uez, owe => oew */
		subst(text, "\\b([ou])([wz])e" SUFFIX_SAFE, "__\\1e\\2\\3__");

		/* CVC with any prefix, and safe ('e' retaining) suffix or just 'e' */
		subst(text, CC "a" C "e" SUFFIX_SAFE "\\b", "\\1ae\\2\\3");
		subst(text, CC "e" C "e" SUFFIX_SAFE "\\b", "\\1ee\\2\\3");
		subst(text, CC "i" C "e" SUFFIX_SAFE "\\b", "\\1iy\\2\\3");
		subst(text, CC "o" C "e" SUFFIX_SAFE "\\b", "\\1oe\\2\\3");
		subst(text, CC "u" C "e" SUFFIX_SAFE "\\b", "\\1ue\\2\\3");

		/* CVC with unstressed prefix, and unsafe suffix */
		subst(text, UNSTRESSED CC "a" C SUFFIX_UNSAFE "\\b", "\\1\\2ae\\3\\4");
		subst(text, UNSTRESSED CC "e" C SUFFIX_UNSAFE "\\b", "\\1\\2ee\\3\\4");
		subst(text, UNSTRESSED CC "i" C SUFFIX_UNSAFE "\\b", "\\1\\2iy\\3\\4");
		subst(text, UNSTRESSED CC "o" C SUFFIX_UNSAFE "\\b", "\\1\\2oe\\3\\4");
		subst(text, UNSTRESSED CC "u" C SUFFIX_UNSAFE "\\b", "\\1\\2ue\\3\\4");

		subst(text, "(ae|ee|ei|iy|oe|ue|ag|ig|og|ug)" ROMANCE_SIGNAL "\\b", "\\1\\2e");
		subst(text, "([^y])ze\\b", "\\1z");
	}

	if (!vflag)
		subst(text, "__([^_]_?[^_]*)__", "\\1");
	
	printf("%s\n", text);

	return 0;
}

