/* Fast PWM example with duty cycle selection via OCR0B
 * Built for ItsyBitsy 32u4 5V 16MHz
 * 
 */

void setup(){

  cli();//stop interrupts
  
  //set timer2 interrupt
  TCCR0A = 0;               // set entire TCCR1A register to 0
  TCCR0B = 0;               // set entire TCCR1B register to 0
  TCNT0  = 0;               //initialize counter value to 0

  TCCR0A = 0x23;          // 0b00100011 --> COM2A1 COM2A0 COM2B1 COM2B0 X X WGM21 WGM20 
                          //                  0       0     1      0    0 0   1     1    --> Clear OCR2B on compare match, fast PWM (waveform generation mode)
  TCCR0B = 0x0A;          // 0b00001100 --> FOC2A FOC2B X X WGM22 CS22 CS21 CS20 
                          //                  0      0  0 0   1    0    1     1         --> fast PWM, interrupt generated at OCR2A, prescaler = 64
                          // set OCR0A to 1000hz increments
  OCR0A = 125;            // = (16*10^6) / (1000*64) - 1 -- 30khz: 
  OCR0B = 62;             // This is the compare value at which the output will be cleared

  sei();//allow interrupts

  pinMode(3, OUTPUT);

}

void loop(void){
  // put your main code here, to run repeatedly:

}
