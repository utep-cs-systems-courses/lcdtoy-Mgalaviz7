#ifndef buzzer_include
#define buzzer_include

void buzzer_init();

void high_note();

void low_note();

void buzzer_set_period(short cycles);

void note_duration(int rest);

#endif //included
