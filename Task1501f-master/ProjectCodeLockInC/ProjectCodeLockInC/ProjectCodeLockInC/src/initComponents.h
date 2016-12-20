/*
 * initComponents.h
 *
 * Created: 2015-12-16 10:43:38
 *  Author: Daniel Petersén and Marcus Sandberg
 */ 

#ifndef INCFILE1_H_
#define INCFILE1_H_
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define GPIO_DIR_OUTPUT (1 << 0)
#define GPIO_DIR_INPUT (0 << 0)

typedef enum {INPUT, OUTPUT} mode_definition;

void pinMode(int pinMode, mode_definition mode);

void digitalWrite(int pinMode, int value);

int digitalRead(int pinNumber);

void testComponents();

void init();

#endif /* initComponents.h */