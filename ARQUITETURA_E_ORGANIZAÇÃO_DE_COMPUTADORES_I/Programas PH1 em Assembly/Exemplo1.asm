;Exemplo de assembly
         text
loop:    LDR i
         SUB v5
         JEQ fim
         STR i
         JMP loop
fim:     HLT

         data
i:       byte 40
v5:      byte 5
