#include <avr/io.h>

uint8_t duty = 0;
uint8_t counter = 0;

int main(void) {
  DDRD |= ( 1 << DDD6);
  OCR1A = duty; // half

  TCCR1A |= (1 << COM1A1);
    // set none-inverting mode

  TCCR1A |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode

  TCCR1B |= (1 << CS01);
    // set prescaler to 8 and starts PWM


  while (1) {
    

    if (counter++ == 0) {
      duty += 1;
    }
  }
}
