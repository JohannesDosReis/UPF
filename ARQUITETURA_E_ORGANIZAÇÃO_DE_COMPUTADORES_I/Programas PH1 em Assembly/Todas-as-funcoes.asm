    text
    NOP
    LDR zero
    STR NOPr

    LDR um 
    STR LDRr


    LDR dois
    STR STRr

    LDR um
    ADD dois
    STR ADDr

    LDR quatro
    SUB um
    STR SUBr

    LDR um
    MUL cinco
    STR MULr

    LDR doze
    DIV dois
    STR DIVr

    LDR tonot
    NOT
    STR NOTr

    LDR quinze
    AND oito
    STR ANDr

    LDR oito
    OR  um
    STR ORr

    LDR quinze
    XOR cinco
    STR XORr

    JMP tojmp
endjmps:
    LDR varjeq
    JEQ tojeq

    LDR varjg
    JG tojg

    LDR varjl
    JL  tojl
    
    HLT

tojmp:
    LDR onze
    STR JMPr
    JMP endjmps

tojeq:
    LDR doze
    STR JEQr
    LDR um
    STR varjeq 
    JMP endjmps

tojg:
    LDR treze
    STR JGr
    LDR zero
    STR varjg 
    JMP endjmps

tojl:
    LDR quatorze
    STR JLr
    LDR zero
    STR varjl 
    JMP endjmps

        data
NOPr:    byte 0
LDRr:    byte 0
STRr:    byte 0
ADDr:    byte 0
SUBr:    byte 0
MULr:    byte 0
DIVr:    byte 0
NOTr:    byte 0
ANDr:    byte 0
ORr:     byte 0
XORr:    byte 0
JMPr:    byte 0
JEQr:    byte 0
JGr:     byte 0
JLr:     byte 0
HLTr:    byte 0

zero:   byte 0
um:     byte 1
dois:   byte 2
quatro: byte 4
cinco:  byte 5
doze:   byte 12
tonot:  byte -8
oito:   byte 8
quinze: byte 15
onze:   byte 11
treze:  byte 13
quatorze:   byte 14
varjeq: byte 0
varjg:  byte 1
varjl:  byte -1
