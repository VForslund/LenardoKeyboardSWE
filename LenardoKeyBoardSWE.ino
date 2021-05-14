                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         #include <HID-Project.h>
#include <HID-Settings.h>


#include <avr/pgmspace.h>


//#include <Keyboard.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define KEY_LEFT_ALT 130
#define KEY_PAD_ZERO 98
#define KEY_PAD_ONE 89
#define KEY_PAD_TWO 90
#define KEY_PAD_THREE 91
#define KEY_PAD_FOUR 92
#define KEY_PAD_FIVE 93
#define KEY_PAD_SIX 94
#define KEY_PAD_SEVEN 95
#define KEY_PAD_EIGHT 96
#define KEY_PAD_NINE 97


#define PIN_ONE 6
#define PIN_TWO 7
#define PIN_THREE 8
#define PIN_FOUR 9
#define PIN_FIVE 2
#define PIN_SIX 3
#define PIN_SEVEN 4
#define PIN_EIGHT 5

char *Songs[] = {"1vrEljMfXYo",
                 "6E5m_XtCX3c",
                 "EIkDE67Z5zM",
                 "SDTZ7iX4vTQ",
                 "12vh55_1ul8",
                 "6VDI0QClEnY",
                 "FJNd007TqLg",
                 "B-RR9wsa12Q",
                 "_RzOh8Oyaxk",
                 "DJztXj2GPfk",
                 "NdqbI0_0GsM",
                 "0mYBSayCsH0",
                 "bWcASV2sey0",
                 "qkUVToIfrKg",
                 "ULrxa1KVzZU",
                 "9fWxCIi5PIw",
                 "b1d7Llx4rm8",
                 "7ioBqAeQrr0",
                 "O2KoBDjCBJs",
                 "uWu4aynBK7E",
                 "qGyPuey-1Jw",
                 "f55CqLc6IR0",
                 "LDU_Txk06tM",
                 "Hiu1hPdJk-Y",
                 "PhiSgXz_l20",
                 "z_HWtzUHm6s",
                 "-R3Td7YWBzg",
                 "Iugi98egpZM",
                 "JlEg5vSEY3s",
                 "OWNOQA6fWC8",
                 "p1U4gkcp_40",
                 "MzovR0s7EbI",
                 "GMZ5DQXEVVo",
                 "aBkTkxKDduc",
                 "CMU2NwaaXEA",
                 "IP68OX_92cw",
                 "ZYJPcxAHaqQ",
                 "2Ik51943WQE",
                 "AIzMtuSPT18",
                 "lYKo-BRwf2A",
                 "Wl959QnD3lM",
                 "cCUmDJ0eU80",
                 "hfjHJneVonE",
                 "SyfsL1DqEQw",
                 "PZJYcdwJTW4",
                 "RRYXVFa2Bsg"
                };

int state = 1;
long randNumber;
size_t n = NELEMS(Songs);


void setup() {
  // put your setup code here, to run once:


    Serial.begin(9600);

  pinMode(PIN_ONE, INPUT);
  pinMode(PIN_TWO, INPUT);
  pinMode(PIN_THREE, INPUT);
  pinMode(PIN_FOUR, INPUT);
  pinMode(PIN_FIVE, INPUT);
  pinMode(PIN_SIX, INPUT);
  pinMode(PIN_SEVEN, INPUT);
  pinMode(PIN_EIGHT, INPUT);


  digitalWrite(PIN_ONE, 1);
  digitalWrite(PIN_TWO, 1);
  digitalWrite(PIN_THREE, 1);
  digitalWrite(PIN_FOUR, 1);
  digitalWrite(PIN_FIVE, 1);
  digitalWrite(PIN_SIX, 1);
  digitalWrite(PIN_SEVEN, 1);
  digitalWrite(PIN_EIGHT, 1);


  Keyboard.begin();
    delay(100);
    Consumer.begin();

  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:

  state = digitalRead(PIN_ONE);
  if (state != 1) {
     delay(10);
Keyboard.press(KeyboardKeycode(0xE6));
 delay(10);
Keyboard.write(KeyboardKeycode(0x62));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5A));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5A));
 delay(10);
Keyboard.write(KeyboardKeycode(0x61));
     delay(10);
Keyboard.releaseAll();

    delay(150);


  }

  state = digitalRead(PIN_TWO);
  if (state != 1) {
     delay(10);
Keyboard.press(KeyboardKeycode(0xE6));
 delay(10);
Keyboard.write(KeyboardKeycode(0x62));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5A));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5A));
 delay(10);
Keyboard.write(KeyboardKeycode(0x60));
     delay(10);
Keyboard.releaseAll();

    delay(150);
  }

  state = digitalRead(PIN_THREE);
  if (state != 1) {
     delay(10);
Keyboard.press(KeyboardKeycode(0xE6));
 delay(10);
Keyboard.write(KeyboardKeycode(0x62));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5A));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5C));
 delay(10);
Keyboard.write(KeyboardKeycode(0x5E));
     delay(10);
Keyboard.releaseAll();

    delay(150);
  }

  state = digitalRead(PIN_FOUR);
  if (state != 1) {
          Consumer.write(MEDIA_PLAY_PAUSE);
    delay(200);

  }

  state = digitalRead(PIN_FIVE);
  if (state != 1) {
          Consumer.write(MEDIA_NEXT);
          Serial.print("Workls:");
    delay(200);

  }

  state = digitalRead(PIN_SIX);
  if (state != 1) {
          Consumer.write(MEDIA_PREVIOUS);
    delay(200);

  }

  state = digitalRead(PIN_SEVEN);
  randNumber = random(n);
  if (state != 1) {
    Keyboard.print("!p https://www.youtube.com/watch?v=");
    Keyboard.println(Songs[randNumber]);
    delay(200);
  }

  state = digitalRead(PIN_EIGHT);
  if (state != 1) {
    Keyboard.println("!s");
    delay(200);
  }
}
