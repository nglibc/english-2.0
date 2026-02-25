# ENGLISH 2.0
What a simpler, more orthogonal and phonetically pure English would look like.

# Compilation and usage
Compile main.c as follows:
```
cc -o english2 main.c
```

The following will convert top 2000 words and also produce some sample sentences:
```
./english2
```
(You might want to pipe to less or more to view a page at a time).

The following will convert a given phrase:
```
./english2 "I am translated to English 2.0"
```

# Example sentences
```
the love of liberty and the hoep for a better liyf must kome to restore happiness.
our brothers and mothers have nowe bekome the some who gaeve all for the many.
the judje in prahg must proove that justice is not a dove that flighs above our reach.
in towne, a duzen more wumen stood in two straight liynes at the heïght of noon.
none should shove aziyd the truth or mistranslaet the dialoges of the diviyn.
we have purified honey and money for the munk to diyn. the leag and voege are heer.
the fatiyge of the plaege was heavy. he baught bread whiyl kughfing near the trughf.
the joürney in the raviyn was long. they faught for the rughf and saught the light.
the quick browne fox jumped over the laezy dog. keep me updaeted on the marketing plan.
rekonciyl the kompiyler output with stockpiyled data on the mobile phoen over there.
```

This is the original English:
```
the love of liberty and the hope for a better life must come to restore happiness.
our brothers and mothers have now become the some who gave all for the many.
the judge in prague must prove that justice is not a dove that flies above our reach.
in town, a dozen more women stood in two straight lines at the height of noon.
none should shove aside the truth or mistranslate the dialogues of the divine.
we have purified honey and money for the monk to dine. the league and vogue are here.
the fatigue of the plague was heavy. he bought bread while coughing near the trough.
the journey in the ravine was long. they fought for the rough and sought the light.
the quick brown fox jumped over the lazy dog. keep me updated on the marketing plan.
reconcile the compiler output with stockpiled data on the mobile phone over there.
```

# Scope and help wanted!!!
Initial scope of this translator is the top 2000 words. Other words may work
but haven't been verified as conforming to the English 2.0 specifications.

Lower case text only is supported.

**If you spot any errors in the top 2000 words that you think don't reflect the
spec below, please create a github Issue for me to fix.**

# English-2.0 specifications
English 2.0 preserves familiar spelling while offering an easy way to show
true pronunciation when needed. It halves current English complexity by
reducing two parallel Long Vowel systems (Magic E and Vowel Teams) to just
the latter.  Vowel teams & consonants are also simplified so that English
becomes clearer without losing its history.

This system is aims for simplicity & orthogonalilty, so that pronunciation
of the general lexicon can be specified within 120 lines (80 columns) of
formal rules. The regular rule pattern also provides strong guidance for
writing, often cutting ambiguity down to 2-3 homophone choices or less.

## TWO MODES OF ENGLISH 2.0:
-  APPROXIMATION MODE: A frictionless, familiar script for daily typing.
   It retains traditional word shapes & many heritage spellings. By using
   only the ASCII character set, it is universally compatible.
-  FIDELITY MODE: The high-resolution version of the language. It uses the
   diaeresis (¨) to provide explicit phonetic fidelity. It signals exactly
   where syllables break and where sounds decay.
-  FRICTIONLESS TRANSITION: Because diaeresis is only non-ASCII feature,
   the transition between modes is purely the adding or stripping of dots.
   Exception: Fidelity voiceless (tħink) uses tħ and voiced (the) uses th.

Together, these modes bridge the gap between historical heritage and
modern phonetic logic without requiring a massive rewrite of the lexicon.

## PRE-PROCESSING: CONSONANT SPECIALISATION & PHONETIC REFINEMENT
- Soft 'c' mandate: 'c' restricted to ce/ci/cy/ch/ck or /ʃ/ else 'c'=>'k',
  where /ʃ/ occurs in the trigraphs -(ci/ti)\[aeiou] (without diaeresis).
- Soft 'g' mandate: 'g'=>'j' for gy/ge/gi (non Germanic); otherwise 'g'.
- Buzzed 's': becomes 'z', except word-final 's' keeps 's' even if buzzed,
  hence plurals, possessives, functional (as, is, was, has, does) use 's'.
- Buzzed 'x': 'xz' btw vowels or before voiced consonants, else just 'x'.
- W words: wone/wonce & one/once spelt with 'o' (see also Scribal O below),
- QU/GU words: word-initial qu/gu always retain u; drop medial silent u.

## MID-PROCESSING: REVERSE MAGIC E (RME)
Having two systems for Long Vowels (Magic E vs Vowel teams) is duplication
of complexity. English 2.0 reduces this to one (in the general lexicon):
- Liquidation of Silent Magic E (LongV-C-e) in favor of Vowel-E (V-e-C).
- Short vowel (eg. Scribal O) words must be protected from RME processing.
- Fixed Teams: ae, ee, iy, oe, ue - eg. gate=>gaet, rode=>roed, some=>some

Treatment of -ite/ide/ire words, and -ate verbs:
- General Lexicon: if end is Long Vowel => -iy/ae RME (except -itë below).
- Science Name Registries: all of these also retain existing trigraphs.
- Hence common science words are dual forms (eg. carbonaeted, carbonated).
- Dual form iff \[scientific registry && common usage]. ~20 words/top 50K.

Treatment of -ice/ive/ine/ile words, and -ate nouns:
- Generally only atomic (1 syllable) are Long I => RME applies to these.
- The -pile/file/koncile non-atomics also Long I -ile => iyl RME words.
- The -b/f/l/n/p/sh/w/vine non-atomics are Long I -ine => iyn RME words.
  (note: give, masculinë, femininë, disciplinë: no RME, retain -e).

Treatment of are/ere/ore/ure words:
- Always short R-Controlled Vowels +/- unstressed => RME does not apply.

## POST-PROCESSING: REGULARISE REMAINING -E
- Terminal E: RME collapses terminal 'e' into Scribal/Geovariant mark.
- Scribal O: must end in 'e', 'er' or 'ey' (some, love, mother, money).
- Protective 'e': -ce/je/se/ve (never bare ending), -iyze & u-glide words.
- Guard to 's[^s]': distinguishes singular (buse, gase, irise) vs plural.
- Noun Reduced Vowel -ate: signals noun form of '-aet' verb (isolate).
- USA Short Vowel -ile: signals dialect swing (same spelling for USA & UK)
- French Vowel -ine: signals Long E (machine vs femininë/masculinë).
- Romance markers -e, -ion, -ic, -ment, -able/el: are result but not rule.

## SHORT VOWEL SPECIALISATION                                              
Schwa representation remains a shortcoming (no direct representation).
Short vowels are single vowels. Vowel teams are described in next section.
Word-final letter vowels are Long (O, U), Schwa/Broad (A) or Silent (E).
Word-initial Long 'O' if multisyllable word & single consonant after O.
```
a       Short A /æ/, except for AR /ɔr/ digraphs. Broad A /ɑ/ is accepted  
        as alternative in many words & mandatory in most 'wa' words.       
e       Short E /ɛ/, ~/ɪ/(if unstressed prefixes: be-, de-, re-).          
i       Short I /ɪ/, except for atomic 'I'.                                
o       Short O /ɑ~ɒ/, except for Scribal O and Long OO (in to, do, who).  
u       Short U /ʌ/, ~/ə/(if unstressed) or Short OO (puyt, fuyll, puysh). 
```

6. OTHER VOWEL SPECIALISATION
Vowels can be (a) internal to word, (b) terminal at end of word/root word,
(c) junctional (two separate syllables), (d) atomic 1-syllable root word.

Some vowel teams are denoted as "swing". These teams vary in pronunciation
between dialects, but have same (global) spelling regardless of dialect.
Characterisation as "Romance" or "Germanic" is approximate, not absolute.
```
ai/ae   Internal Long A. Stressed (rain, staek on plaet, paeling staek).   
        Used by Germanic roots. Unstressed Romance decay uses ï (captaïn). 
ate     Scientific Terminal Long AT. Stressed. In contrast -atë is at-ë.   
ay      Terminal Long A (day, pray). Unlike -ey, it doesn't decay.         
        Remains a sharp Long A even if unstressed (holiday).               
au      Broad AW diphthong (wauter, kaughf, traughf).                      
iy/ify  Standard/Terminal Long I. Stressed (subliym, justify, hydroliyze). 
igh     Germanic Terminal Long I. Stressed/heavy (fligh, drigh, sligh).    
ite/ide Scientific Terminal Long IT/ID. Stressed. In contrast -itë is it-ë 
        junction (eg. favoritë, -o/-isitë, -ueritë, elitë/petitë/suitë).   
i[^td]e Terminal Swing /ɪ~i/. Unstressed suffixes (-ile/ne/ce/ve/se).      
        Atomics & Long I derivs move to iy lane (eg. viyce, liyn, hiyve).  
y       Terminal Swing /ɪ~i/. Unstressed multi-syllables (happy, carry).   
        Atomic Long I (why). Non-atomic+stress uses ÿ/ify (supplÿ=suppl-y).
ie      Junctional Swing /ɪ~i/. Unstressed. Diaeresis is break (happiëst). 
        Atomic Long I (eg. die, pie).                                      
ey      Terminal Swing /ɪ~i/. Unstressed. Scribal marker for O (honey).    
        Atomic Long A (they, hey). Evict non-atomic+stress to 'ay' (obay). 
ei      Multisyllable Long E (receive, deceit). Atomic Long A (eight, vein)
ea/ee   Standard Long E (feel, meet). Distinguishes Germanic roots from    
        the Romance 'ie' lane.                                             
oa/oe   Standard Long O (boat, road, toe). Used for Germanic roots where   
        vowel is internal 'oa' followed by consonant, or terminal 'oe'.    
ow      Terminal Lazy O (yellow). Suffixing -er/-ed (lowër) has diaresis.  
        Atomic Long O (low, grow).                                         
ou      Internal OW diphthong /aʊ/ (house, cloud, south).                  
        Long OO words are evicted to 'ue' (eg. soup=>suep).                
oü      Junction with short U collapse (doübel, koüntry).                  
ow[n]e  Internal & terminal OW diphthong (howe, towne, scowel, flower).    
        Note: Reverse magic E rule transforms (only) 'owe' to 'oew'.       
oo/ue   Details TBD. Scribal O rules apply to flo/blo-od (bloode, floode). 
ar      Standard R-Controlled AR /ɑr/ (arë, far).                          
are/air Terminal R-Controlled AIR /ɛr/ (hare, hair; evict word are=>arë).   
ear/eer Terminal R-Controlled EAR /ɪr/ (near, heer; evict bear=>bere).      
ere     Multisyllable R-Controlled EAR /ɪr/ (sincere). Stressed.            
        Atomic R-Controlled AIR /ɛr/ sound (where, there; evict here=>ee).  
er/ur   Romance R-Controlled Vowel IR/ER /ɝ~ər/ (nurse, serve).            
        or Scribal O family (other, mother & bother to have 'o' = /ʌ/).    
ir      Germanic Metathesis R-Controlled Vowel IR/ER /ɝ~ər/ (bird).        
or/ore  R-Controlled Vowel OR /ɔr/ (for, more). Note 'ore' not Scribal O).  
wor     R-controlled vowel + W-glide (work, word): use 'o' transition mark 
ough    Terminal Long O words only. Evict all others to -owe (plowe),      
        -ue (thru), -aught (baught) or -aughf (kaughf).                    
ure     Terminal R-Controlled URE.                                          
```

## DOUBLE CONSONANT SPECIALISATION
Double consonants mark stressed final short vowels of the base word. They
are not needed in initial syllables, which are stressed by default, if the
final syllable is not stressed. Hissed 'ss' are retained as the exception.

## SYLLABIC JUNCTIONS & DIAERESIS OPERATORS
- The diaeresis (¨) signals a "Junction" where a vowel team is broken or
  a phonetic lane shift occurs due to rhythmic decay or heritage.
- MODAL USE: In "Fidelity" mode, it ensures full phonetic fidelity. In
  "Approximation" mode, it is omitted for frictionless heritage typing.
- JUNCTION BREAKS: Placed on the second vowel to separate a root from a
  suffix (doïng, beïng, lowër) or to distinguish from a protected team
  (lowër vs flower). This preserves root-word recognition.

# Top 2000 words list
(Text columns are misaligned, but this is useful in seeing which words are lengthened or
shortened in English 2.0).
```
the        I          to         and        a          of         was        he        |
yue        it         in         her        she        that       my         his       |
me         on         with       at         as         had        for        but       |
him        saïd       be         up         out        look       so         have      |
what       not        just       liyk       go         they       is         this      |
from       all        we         were       back       do         one        about     |
know       if         when       get        then       into       would      no        |
there      kould      ask        downe       tiym       want       eye        them      |
over       your       are        or         been       nowe        an         by        |
think      see        hand       say        howe        around     head       did       |
well       before     off        who        more       even       turn       kome      |
smiyl      way        really     kan        faece       other      some       right     |
their      only       walk       maek       got        try        something  room      |
again      thing      after      still      thaught    door       heer       too       |
little     bekauz    why        away       let        taek       two        start     |
good       wheer      never      thru    day        much       tell       girl      |
feel       oh         kall       talk       will       long       than       us        |
maed       friend     knew       open       need       first      which      people    |
went       suer       seem       stop       voice      very       felt       took      |
our        pull       laghf      man        okay       kloez      any        kaem      |
told       love       watch      arm        anything   though     put        left      |
work       guy        hair       next       yeah       whiyl      mean       hoem      |
few        saw        plaece      skool     help       wait       late       year      |
houz      happen     last       always     moove       old        night      nod       |
liyf       give       sit        stare      sat        should     moement     another   |
behind     siyd       sound      once       fiynd       toward     boy        ever      |
nothing    front      mother     naem       am         since      reply      myself    |
leave      bed        new        kar        uez        miynd       maybe      has       |
heard      answer     minuet     yes        until      both       found      end       |
small      word       someone    saem       enughf     began      run        bit       |
sigh       each       thoez      almost     against    everything most       thank     |
mom        better     play       own        every      hard       remember   three     |
stood      liyve       stand      sekond     sorry      keep       finally    point     |
gaeve       already    aktually   probably   himself    big        everyone   guess     |
lot        step       hey        hear       light      quickly    dad        kiss      |
black      pick       else       soon       shoulder   table      best       without   |
notice     stay       kare       phoen      reach      realiyze    follow     deciyd    |
kiynd       grab       show       insiyd     suddenly   father     rest       herself   |
grin       hour       hoep       also       body       might      floor      its       |
kontinue   ran        akross     hold       kry        half       pretty     great     |
kourse     mouth      klass      kid        miss       wonder     morning    least     |
niyce       dark       slowly     done       chanje     together   yet        question  |
anyway     bad        blue       believe    week       God        lip        Mr.       |
sleep      fiyn       family     many       worry      roll       paerent     under     |
surpriyze   water      onto       glance     wall       between    seen       read      |
window     idea       whiyt      push       feet       must       such       seat      |
set        pleaz     red        brother    theez      whoel      lean       part      |
person     slightly   pass       shook      fakt       wrong      goen       far       |
hit        finger     quiyt      hate       meet       fiynish     heart      book      |
past       kill       reazon     anyone     figuer     top        along      world     |
high       shirt      does       today      young      held       outsiyd    listen    |
whisper    happy      ground     deep       drop       shrug      dress      fell      |
yell       breath     air        tear       sister     chair      kitchen    matter    |
hurt       fall       wear       wuman      eat        lie        hell       suppoez   |
kover      kouple     larje      either     fiyve       leg        jump       die       |
return     able       bag        aloen      shut       stuff      short      ready     |
understand kept       plan       raiz      street     different  problem    break     |
liyn       early      kut        kold       paeper      skream     instead    stupid    |
silence    tree       kaught     ear        food       full       four       kauz     |
fuck       explain    expekt     fight      exaktly    sort       kompleetly men       |
dance      met        story      whatever   build      speak      glass      pain      |
check      glare      korner     Mrs.       chest      hot        rather     month     |
real       touch      park       bring      drink      ago        force      fast      |
lost       attention  wish       mark       waeve       shout      fill       begin     |
baeby       inteerest   money      fun        green      however    cheek      mine      |
klear      browne      forward    near       pikturë    may        kool       driyve     |
hug        shaek      sense      alright    dream      hang       klothes    akt       |
bekome     manaej     meant      gaem       ignore     stair      taken      party     |
add        sometiyms  job        ten        shot       date       quiet      gaez      |
gruep      loud       straight   dead       neck       beziyd     pauz      number    |
konversation chance   roez       quietly    towne       blood      kolor      desk      |
dinner     hall       horse      muzik      braught    piece      anymore    beautiful |
order      fiyr       office     true       although   warm       easy       enter     |
perfekt    mutter     softly     kross      shock      smirk      damn       soft      |
stomach    snap       spoek      tiyr       box        katch      skin       teacher   |
middle     noet       yourself   lunch      tomorrow   breathe    klean      except    |
appear     lock       knock      bathroom   movie      agree      offer      kick      |
form       konfuez    lay        less       kalm       slip       sign       dog       |
lift       immediately arriyve    deal       tonight    uzually    kaez       frowne     |
shop       skare      promiyze    mum        kouch      pay        staet      shit      |
wrap       pocket     hello      free       huej       riyd       bother     land      |
known      especially expression karry      ring       spot       allowe      several   |
duering     empty      laedy       eyebrowe    stranje    koffee     road       threw     |
wiyd       bus        forjet     gotten     smell      fear       press      boyfriend |
blonde     throw      round      sun        tall       glad       aje        wriyt     |
upon       hiyd       bekaem     krowd      rain       saeve       trouble    annoy     |
noez       weird      death      beat       toen       trip       six        kontrol   |
nearly     konsiyder   gonna      join       learn      above      hi         obviousligh |
entiyr     direktion  foot       angry      poewer      strong     quick      doktor    |
edje       song       asleep     twenty     baerly     remain     child      enjoy     |
gun        slow       ciyty       broek      key        lead       throat     normal    |
somewheer  waek       pair       skigh        funny      buziness   student    gigge    |
bright     admit      jeans      jiven      children   store      sweet      low       |
klimb      rub        apartment  knee       shoe       attack     bedroom    joek      |
spent      situation  stuck      jently     possible   cell       mention    siylent    |
definiytly rush       hung       brush      perhaps    groan      ass        rock      |
kard       loez       blush      beziyds    kraezy      type       bore       afraid    |
chaez      respond    marry      remiynd     pack       daughter   serious    jirlfriend|
mad        somehowe    buy        sent       tight      simply     trust      imajine   |
wind       chuckle    bar        pink       shove      ball       sight      drag      |
human      truth      share      area       koncern    team       eskaep     mumble    |
often      search     apparently attempt    son        within     band       kuet      |
led        memory     anger      fligh        paint      bottle     buesy       komment   |
exklaim    avoid      grow       grey       mirror     gasp       hallway    dear      |
star       sick       kat        kounter    interrupt  none       blink      spend     |
uzual      worse      locker     important  favoriyt   grip       TV         ice       |
pretend    settle     amaez      pop        dizappear  karefully  train      stick     |
guard      teeth      flash      unkle      send       doubt      vizit      nervous   |
exciyt     approach   exkuez     fit        noiz      study      letter     police    |
eventually burn       field      hospital   tie        summer     huh        shift     |
self       hurry      greet      wiyf       pozition   wiyp       heavy      slam      |
broken     kompleet   spaece      brain      tiyny       pants      ah         punch     |
shoewer     tunge     afternoon  seriousligh  kup        further    raece       rekogniyze |
kompueter   rang       saef       jacket     bottom     hundred    relax      sudden    |
wowe        kolleej    flip       mood       track      krack      block      handle    |
themselves droeve      seven      struggle   whether    ahead      sad        dry       |
wumen      fokus      repeat     thick      relationship jerk     preezent    suck      |
bell       surround   evening    biyt       single     fault      shadow     wood      |
eazily     woek       smoek      draw       sugjest    wet        akcept     third     |
totally    wore       breakfast  trail      animal     warn       aunt       sir       |
piss       burst      match      fix        praktikally odd       wosh       sing      |
inch       siyze       sekret     klock      kompany    view       suit       forever   |
familiar   forehead   shoot      grew       stretch    pound      despiyt    response  |
center     kurl       slight     toss       beneath    fist       welkoem    laughter  |
anjel      Christmas  main       simple     neither    distance   komfort    upset     |
assuem     eight      gather     lucky      faed       Ms.        koat       special   |
awkward    certain    plate      darkness   praktice   obvious    graed      kream     |
choice     hardly     pael       thin       button     chokolate  refuez     slid      |
pillow     thirty     kount      honestly   poor       moetion     storm      lightly   |
nobody     experience path       period     dare       demand     komfortable klearly  |
silver     peer       birthday   disgust    embarrass  baught     test       lap       |
bet        loudly     driyver     murmur     taste      perfektly  squeez    board     |
worth      fold       spread     krap       emotion    subjekt    pour       laid      |
loewer      mile       yea        paej       piyl       snow       messaej    English   |
sceen      sink       fail       forgot     hoel       silently   heat       weekend   |
drew       guitar     sweat      unless     kloud      waist      slap       argue     |
grass      idiot      skreen     yesterday  swear      twin       instantly  apart     |
narrow     oppoziyt   blow       wrist      earth      aktion     cirkle     forgotten |
list       klozet     drunk      shaep      yellow     twist      weight     smart     |
treat      pool       prepare    awaek      certainly  teaz      kontakt    sliyd     |
wonderful  bitch      reveal     swing      truck      anywheer   flower     upstairs  |
hers       itself     wander     downstairs football   possibly   rip        foerest    |
mostly     bloody     chirchch     gay        stoen      husband    sex        trick     |
yours      growel      klub       Friday     staej      inklued    sip        inviyt    |
sharp      konvince   sheet      absoluetly oranje     relief     apolojiyze  art       |
remoove     krash      van        kurse      aliyve      blanket    receive    tip       |
riyze       tightly    waste      bowl       fallen     river      mama       paece      |
honey      swallow    king       kamera     dezerve    dirty      chin       doorway   |
imaej      kookie     homework   hat        luck       aziyd      information fifteen  |
fair       player     monster    gate       win        below      ceiling    klick     |
kook       travel     fish       lit        nervousligh  towel      shiver     final     |
horrible   station    kamp       hungry     thouzand   evil       rich       war       |
involve    jaw        unkomfortable direktly level     double     niyn       kreaturë  |
glow       somewhat   blaem      entrance   hip        fresh      hiss       normally  |
tap        machine    ruin       bear       ruel       till       kock       stumble   |
komplain   everybody  truely      nurse      speed      hmm        panik      smooth    |
weak       good-bye   extra      jesturë    skowl      beer       releaz    kountry   |
officer    kareful    kreate     hill       snort      flew       heel       browe      |
charje     flat       plus       switch     whenever   drift      metal      diskover  |
wheel      skirt      pat        ate        tea        hotel      sob        futurë    |
rekord     boot       liykly     cheer      gold       proove      ha         twiyce     |
aware      lack       princess   bench      kouzin     detail     amount     bird      |
backward   krush      cigarette  faint      belong     stranger   beach      load      |
everywheer skratch    history    restaurant event      extreemly  widen      klutch    |
due        tug        beyond     happily    mistaek    palm       amuez      guest     |
Saturday   wooden     worst      exit       plastik    reality    wince      announce  |
gotta      slept      member     chooz     Dr.        swim       alarm      krawl     |
dollar     kniyf      majik      paid       pizza      purse      gift       chicken   |
plaen      choek      skrew      proetest    baez       drug       introduece  sleeve    |
moevment   looz      bare       wanna      diffikult  fraem      spin       faek      |
pen        understood nor        unfortunaetly written  deciyzion  beg        heavily   |
insist     soul       random     sport      mael       urje       million    yawn      |
backpack   judje      startle    bunch      stream     muskle     yard       akcident  |
dragon     sentence   fool       torn       bow        echo       mix        buery      |
system     dirt       spirit     leaf       protekt    row        forth      purple    |
bang       kurious    nearby     nowheer    kollapse   hop        proud      wing      |
destroy    sea        separate   silly      wuend      hoenest     battle     born      |
kughf      mountain   split      square     underneath biyk       process    somebody  |
klassroom  prezence   whoez      grown      hidden     serve      femael     garden    |
meal       unable     elbow      support    bridje     reaktion   skip       wild      |
angrily    effekt     threaten   bazikally  smack      stroek     flow       moan      |
plant      impossible bruiz     dizappoint enerjy     relieve    konfuezion  wedding   |
fat        bill       dued       address    kast       naeked      toy        math      |
personal   ship       spun       chat       pray       whip       grasp      float     |
fully      gorjeous   indeed     nail       viyzion     innoecent   friendly   jealous   |
swung      flaem      dorm       driveway   spill      gang       murder     respekt   |
bent       tail       inform     lesson     whiyn      klench     exciytment library   |
lord       surfaece    dust       dump       featurë    objekt     weapon     kalmly    |
hezitate   hint       law        magazine   among      boss       fiyl       leather   |
rezult     thrown     toe        terrible   lokal      projekt    wun        radio     |
regret     grumble    otherwiyze  ridikulous CD         loevly     mock       effort    |
fan        nerve      report     stall      elevator   mate       bastard    grunt     |
roep       entiyrly   frighten   shaed      strength   boen       exchanje   flight    |
Monday     partner    plain      shiyn      kafeteria  beam       exist      porch     |
queen      squeal     faith      pierce     remark     kontent    eaz       flick     |
mall       kannot     karpet     length     replaece    duck       bump       kommon    |
style      tan        kaek       kourt      previous   balance    bank       blind     |
danjerous  partikular sell       wroet      distrakt   melt       popular    social    |
teach      appearance korrekt    laek       publik     sarkastikally guilty  kinda     |
shall      televizion boat       firmly     tent       thumb      manner     flush     |
roof       scheduel   diyn       weather    kazually   moon       difference butt      |
charm      feed       frustration jentle    hook       bounce     partikularly pleazurë|
sneak      leader     raej       shriek     suffer     Sunday     argument   pregnant  |
diskuss    staetment  ticket     dig        doll       chill      fence      horror    |
buïlt      kop        sekurity   sidewalk   breast     kurtain    whom       fifty     |
jiant      milk       rekall     term       footstep   stun       tuck       klothing  |
lick       joy        ugly       hopefully  soldiër    plead      struck     trap      |
opinion    plenty     tank       breez     awezoem    deziyr     roommate   halfway   |
opportunity outfit    rughf      beauty     choez      snaek      taep       badly     |
cheat      daddy      roar       deskriyb   desperaetly heïght    thigh      tilt      |
deeply     friendship winter     witch      worn       kondiytion  enemy      golden    |
sofa       master     rued       throughout assuer     damaej     natural    steal     |
belt       kaej       klaim      nightmare  preefer     purpoez    meerly     pin       |
French     sadly      uniform    branch     direkt     hunter     juice      charakter |
puer       stain      various    gain       soak       laetly     pitch      akcent    |
tremble    kabin      chew       physikal   puzzle     exploed    steady     pet       |
saek       kompare    principal  skan       forty      impress    mentally   reakt     |
sandwich   shy        twelve     whilst     bullet     challenje  kommand    examine   |
film       appreciate tense      blank      blew       faught     jym        passenger |
teenajer   dish       drawn      skary      unliyk     straighten strain     tuen      |
konstantly famous     marriaje   bound      fancy      issue      warmth     awhile    |
kollekt    koncentrate koepy      disbelief  tighten    determine  favor      mental    |
bush       forjive    aim        embraece    fairly     froez      insult     option    |
post       rezist     spoken     apple      jeneral    instant    jeep       emerje    |
neighbor   pressurë   service    shuffle    briefligh    notebook   peace      string    |
wiyn       dash       gut        stress     konnekt    languaje   private    spring    |
chip       puppy      ache       desperate  habit      necessary  noep       pencil    |
satisfy    denigh       mommy      attitued   dial       painful    display    frustrate |
tend       exakt      powerful   naturë     photo      total      video      egg       |
okkur      anybody    korridor   gulp       traece      whoever    brief      exhaust   |
pout       terrify    chapter    insaen     spell      suerly     tray       alkohol   |
chain      fashion    garaej     inquiyr    kandy      similar    bark       flirt     |
pathetik   supply     toewer      enjine     frozen     map        toilet     background|
shudder    spider     adult      cheap      klue       hazel      irritate   sand      |
quarter    spare      Amerikan   rid        spat       pot        awful      bleed     |
fate       jog        striyk     grimaece    holiday    whistle    agreement  dull      |
expensive  snatch     sometiym   abiylity    kampus     kollar     disturb    flicker   |
proceed    recently   risk       skill      topik      defense    fry        luckily   |
retort     kaptain    eaten      gloeve      mid        owner      cheez     yank      |
afterward  kloezly    koach      feather    handsome   New York   piyty       signal    |
sniff      strap      kontain    survive    sweater    west       draewer     leap      |
major      peek       suspekt    tuer       freez     heaven     mask       surprizingly|
abruptly   begun      kustomer   pad        dezign     flop       priyd      yep       |
interview  makeup     blast      prince     roed       bubble     rent       teen      |
```
