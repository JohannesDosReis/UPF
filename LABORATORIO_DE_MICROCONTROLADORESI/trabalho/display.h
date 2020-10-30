
#define RS RE0
#define E RE1
#define DADO PORTC

void tempo(void) {
  E = 1;
  delay_ms(5);
  E = 0;
}

void lcd_cmd(char cmd) {
  DADO = cmd;
  tempo();
  DADO = ((cmd << 4) & 0xF0);
  tempo();
}

void inicializa(void) {
  E = 0;
  RS = 0;

  // DADO = 0x20;
  // tempo();
  lcd_cmd(0x32); // initialize lcd and start mode 4 bits
  lcd_cmd(0x28); // 4-bit mode - 2 line - 5x7 font.
  lcd_cmd(0x06); // Automatic IncremEt - No Display shift.
  lcd_cmd(0x0C); // Display no cursor - no blink.
  lcd_cmd(0x01); // Address DDRAM with 0 offset 80h.
  RS = 1;
}

void lcd_data(char data) {
  DADO = data;
  tempo();
  DADO = ((data << 4) & 0xF0);
  tempo();
}

void escreve(unsigned char posicao, char t[]) {
  unsigned char i = 0;

  RS = 0;
  lcd_cmd(posicao);
  RS = 1;

  while (t[i] != 0) {
    lcd_data(t[i]);
    i++;
  }
}
