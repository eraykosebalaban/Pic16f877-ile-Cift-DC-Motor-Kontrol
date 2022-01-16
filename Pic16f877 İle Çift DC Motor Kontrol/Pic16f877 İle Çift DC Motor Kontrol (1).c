#include<16f877.h>

#use delay(clock = 4000000)

#use fast_io(a)
#use fast_io(b)

int sayi = 0;

#int_timer0

void timer0_kesme(){
set_timer0(255);
sayi++;

if(sayi %2 == 1){
output_high(pin_b0);
output_low(pin_b7);
}

if(sayi %2 == 0){
output_high(pin_b7);
output_low(pin_b0);
}

if(sayi == 15){
sayi = 0;
}

}

void main(){
setup_psp(PSP_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_ccp1(CCP_OFF);
setup_ccp2(CCP_OFF);

set_tris_a(0x10);
set_tris_b(0x00);

output_b(0x00);

setup_timer_0(RTCC_EXT_L_TO_H | RTCC_DIV_1);

set_timer0(255);

enable_interrupts(INT_timer0);
enable_interrupts(GLOBAL);

while(true);

}

