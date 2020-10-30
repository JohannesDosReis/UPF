     text
               LDR a
               SUB b
               JL menor
               LDR a
               JMP fim
menor:         LDR b
fim:           STR m
               HLT
               data
a:             byte 5
b:             byte 6
m:             byte 0
