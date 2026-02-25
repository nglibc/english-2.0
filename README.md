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
