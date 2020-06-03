//
#include <stdint.h>
#include <stdbool.h>
//#include <stdio.h>
//#include <stdlib.h>

#include "display.h"
#include "wait.h"
//#include "fonts_w.h"

#include "ch.h"
#include "hal.h"

#include "ssd1331.h"

#include "fonts/_images.h"

#include "fonts/Font_3_Tiny.h"
#include "fonts/Font_3_PicoPixel.h"
#include "fonts/Font_3_TomThumb_Extended.h"
#include "fonts/Font_5_Org.h"
#include "fonts/Font_8_Sinclair.h"
#include "fonts/Font_8_Sinclair_Inverted.h"
#include "fonts/Font_8_Tiny.h"
#include "fonts/Font_8_Myke.h"
#include "fonts/Font_8_Default.h"
#include "fonts/Font_8_Retro.h"
#include "fonts/Font_9_Mono.h"
#include "fonts/Font_9_Mono_Bold.h"
#include "fonts/Font_9_Mono_Bold_Oblique.h"
#include "fonts/Font_9_Mono_Oblique.h"
#include "fonts/Font_9_Sans.h"
#include "fonts/Font_9_Sans_Bold.h"
#include "fonts/Font_9_Sans_Bold_Oblique.h"
#include "fonts/Font_9_Sans_Oblique.h"
#include "fonts/Font_9_Serif.h"
#include "fonts/Font_9_Serif_Bold.h"
#include "fonts/Font_9_Serif_Bold_Italic.h"
#include "fonts/Font_9_Serif_Italic.h"
#include "fonts/Font_12_Mono.h"
#include "fonts/Font_12_Mono_Bold.h"
#include "fonts/Font_12_Mono_Bold_Oblique.h"
#include "fonts/Font_12_Mono_Oblique.h"
#include "fonts/Font_12_Sans.h"
#include "fonts/Font_12_Sans_Bold.h"
#include "fonts/Font_12_Sans_Bold_Oblique.h"
#include "fonts/Font_12_Sans_Oblique.h"
#include "fonts/Font_12_Serif.h"
#include "fonts/Font_12_Serif_Bold.h"
#include "fonts/Font_12_Serif_Bold_Italic.h"
#include "fonts/Font_12_Serif_Italic.h"
#include "fonts/Font_16_Arial.h"
#include "fonts/Font_16_Arial_Bold.h"
#include "fonts/Font_16_Arial_Italic.h"
#include "fonts/Font_16_Default.h"
#include "fonts/Font_16_FranklinGothic.h"
#include "fonts/Font_16_Hallfetica.h"
#include "fonts/Font_16_Nadianne.h"
#include "fonts/Font_16_Sinclair.h"
#include "fonts/Font_16_Sinclair_Inverted.h"
#include "fonts/Font_16_Swiss_Outline.h"
#include "fonts/Font_16_Matrix_Full.h"
#include "fonts/Font_16_Matrix_Full_Slash.h"
#include "fonts/Font_16_Matrix_Num.h"
#include "fonts/Font_16_Arial_Round.h"
#include "fonts/Font_16_OCR.h"
#include "fonts/Font_16_Segment_16_Full.h"
#include "fonts/Font_16_Grotesk.h"
#include "fonts/Font_16_Grotesk_Bold.h"
#include "fonts/Font_16_Retro.h"
#include "fonts/Font_18_Mono.h"
#include "fonts/Font_18_Mono_Bold.h"
#include "fonts/Font_18_Mono_Bold_Oblique.h"
#include "fonts/Font_18_Mono_Oblique.h"
#include "fonts/Font_18_Sans.h"
#include "fonts/Font_18_Sans_Bold.h"
#include "fonts/Font_18_Sans_Bold_Oblique.h"
#include "fonts/Font_18_Sans_Oblique.h"
#include "fonts/Font_18_Serif.h"
#include "fonts/Font_18_Serif_Bold.h"
#include "fonts/Font_18_Serif_Bold_Italic.h"
#include "fonts/Font_18_Serif_Italic.h"
#include "fonts/Font_24_Matrix_Num.h"
#include "fonts/Font_24_Inconsola.h"
#include "fonts/Font_24_Ubuntu.h"
#include "fonts/Font_24_Ubuntu_Bold.h"
#include "fonts/Font_24_Segment_16_Full.h"
#include "fonts/Font_24_Mono.h"
#include "fonts/Font_24_Mono_Bold.h"
#include "fonts/Font_24_Mono_Bold_Oblique.h"
#include "fonts/Font_24_Mono_Oblique.h"
#include "fonts/Font_24_Grotesk.h"
#include "fonts/Font_24_Grotesk_Bold.h"
#include "fonts/Font_24_Sans.h"
#include "fonts/Font_24_Sans_Bold.h"
#include "fonts/Font_24_Sans_Bold_Oblique.h"
#include "fonts/Font_24_Sans_Oblique.h"
#include "fonts/Font_24_Serif.h"
#include "fonts/Font_24_Serif_Bold.h"
#include "fonts/Font_24_Serif_Bold_Italic.h"
#include "fonts/Font_24_SerifItalic.h"
#include "fonts/Font_32_Dingbats.h"
#include "fonts/Font_32_Special.h"
#include "fonts/Font_32_Calibri_Bold.h"
#include "fonts/Font_32_Arial_Num_Plus.h"
#include "fonts/Font_32_Matrix_Num.h"
#include "fonts/Font_32_Segment_7_Full.h"
#include "fonts/Font_32_Segment_7_Num_Plus.h"
#include "fonts/Font_32_Segment_16_Full.h"
#include "fonts/Font_32_Segment_18_Full.h"
#include "fonts/Font_32_Grotesk.h"
#include "fonts/Font_32_Grotesk_Bold.h"
#include "fonts/Font_40_Segment_16_Full.h"
#include "fonts/Font_48_Battery.h"
#include "fonts/Font_48_Segment_16_Num.h"
#include "fonts/Font_64_Segment_16_Num.h"
#include "fonts/Font_64_Segment_7_Num.h"

bool is_display_init=FALSE;

void display_print_adc(adcint_t *adc){

  if(!is_display_init) return;

  static int16_t temp = 0;
  char textbuff[16];

  chThdSleepMilliseconds(100);
  if (adc->is_adc_sampl){
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);
    temp++;

    itoa(temp, textbuff, 10);
    LCD_Font(3, 15, textbuff, _8_Myke, 1, WHITE);
    itoa(adc->x_raw, textbuff, 10);
    LCD_Font(3, 35, textbuff, _8_Retro, 1, WHITE);
    itoa(adc->y_raw, textbuff, 10);
    LCD_Font(3, 55, textbuff, _8_Retro, 1, WHITE);

    itoa(adc->volt5_raw, textbuff, 10);
    itoa(adc->voltage_usb, textbuff, 10);
    LCD_Font(47, 15, textbuff, _8_Retro, 1, WHITE);

    itoa(adc->voltref_raw, textbuff, 10);
    itoa(adc->voltage_3v3, textbuff, 10);
    LCD_Font(47, 35, textbuff, _8_Retro, 1, WHITE);

    itoa(adc->temp_raw, textbuff, 10);
    itoa(adc->temp_core, textbuff, 10);
    LCD_Font(47, 55, textbuff, _8_Retro, 1, WHITE);

    adc->is_adc_sampl=false;
  }
}

#define DISPLAY_MAILBOX_NUM_MSGS 8
static msg_t display_mailbox_queue[DISPLAY_MAILBOX_NUM_MSGS];
mailbox_t display_mailbox;
static uint8_t state_display_layer;
static uint32_t demo_retr = 0xFFFFFFFF;

// thread
static THD_WORKING_AREA(oledThread1, 128);
static THD_FUNCTION(funThread1, arg) {
  (void)arg;
  chRegSetThreadName("ThreadDisplay");

  chMBObjectInit(&display_mailbox, display_mailbox_queue, DISPLAY_MAILBOX_NUM_MSGS);

  SSD1331_Init();
  chThdSleepMilliseconds(1);
  SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);
  chThdSleepMilliseconds(1);
  is_display_init = TRUE;

  static uint8_t prev_state_layer;

  msg_t msg;
  char textbuff[8];

  prev_state_layer=get_highest_layer(default_layer_state);

  itoa(prev_state_layer, textbuff, 10);
  LCD_Font(54, 36, textbuff, _16_Retro, 1, WHITE);

  while (true) {

    if(chMBFetchTimeout(&display_mailbox, &msg, TIME_INFINITE) == MSG_OK){

      switch (msg){
        case DISPLAY_TOGGLE_CAPS:
          if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)){
              LCD_Font(6, 36, "a", _16_Retro, 1, BLACK);  // закрашиваю предыдущий символ цветом фона
              LCD_Font(6, 36, "A", _16_Retro, 1, WHITE);
          }else{
              LCD_Font(6, 36, "A", _16_Retro, 1, BLACK);
              LCD_Font(6, 36, "a", _16_Retro, 1, WHITE);
          }
        break;

        case DISPLAY_TOGGLE_LAYER:
          if(prev_state_layer != state_display_layer){
             itoa(prev_state_layer, textbuff, 10);
             LCD_Font(54, 36, textbuff, _16_Retro, 1, BLACK);
             prev_state_layer = state_display_layer;
             itoa(prev_state_layer, textbuff, 10);
             LCD_Font(54, 36, textbuff, _16_Retro, 1, WHITE);
          }
        break;
        case DISPLAY_DEMO_MODE:
          SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);
          display_demo();
          SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);
          chMBPostTimeout(&display_mailbox, (msg_t) DISPLAY_TOGGLE_LAYER, TIME_IMMEDIATE);
          chMBPostTimeout(&display_mailbox, (msg_t) DISPLAY_TOGGLE_CAPS, TIME_IMMEDIATE);
        break;
      }

    }else{  //ошибка в очереди
        ;
    }
    //test();
    //display_demo();
    //chThdSleepMilliseconds(10);
  }
}

void display_star_thread(void) {
  chThdCreateStatic(oledThread1, sizeof(oledThread1), NORMALPRIO + 1, funThread1, NULL);
}


void test(void) {
  static int16_t temp = 0;
  static char textbuff[16];

    temp++;
    //sprintf(textbuff, "%d", temp);
    itoa(temp, textbuff, 10);
    LCD_Font(3, 15, textbuff, _9_Mono, 1, WHITE);
    chThdSleepMilliseconds(1000);
    //SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(1);
    LCD_Font(3, 15, textbuff, _9_Mono, 1, BLACK);//chThdSleepMilliseconds(1);
    //printf
}

void display_demo(void) {
 while (demo_retr){
     demo_retr--;
   //  oled1331_14V_on();
    LCD_Circle(48, 32, 5, 0, 1, BLUE);
    LCD_Circle(48, 32, 10, 0, 1, YELLOW);
    LCD_Circle(48, 32, 15, 0, 1, BLUE);
    LCD_Circle(48, 32, 20, 0, 1, YELLOW);
    LCD_Circle(48, 32, 25, 0, 1, BLUE);
    LCD_Circle(48, 32, 30, 0, 1, YELLOW);
    chThdSleepMilliseconds(2000);
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);

    SSD1331_IMG(IMG0, 0, 0, 96, 64);
    chThdSleepMilliseconds(2000);
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);

    SSD1331_IMG(IMG1, 16,0, 64, 64);
    chThdSleepMilliseconds(2000);
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);

    SSD1331_IMG(IMG3, 32, 16, 32, 32);
    chThdSleepMilliseconds(2000);
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);

    SSD1331_IMG(IMG2, 23, 7, 50,50);
    SSD1331_setScrolling(Horizontal, 0, 64, 1);
	SSD1331_enableScrolling(1);

    chThdSleepMilliseconds(6000);
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);
    SSD1331_enableScrolling(0);

    LCD_Font(5, 25, "SSD1331", _8_Retro, 1, RED);
	LCD_Font(5, 45, "OLED", _12_Mono, 1, GREEN);
	LCD_Font(10, 60, "0123456", _9_Mono, 1, BLUE);

    chThdSleepMilliseconds(1000);
    SSD1331_Frame(0, 0, 95, 63, BLUE, BLACK);chThdSleepMilliseconds(2);

    //SSD1331_setScrolling(Horizontal, 0, 64, 1);
	//SSD1331_enableScrolling(1);

    chThdSleepMilliseconds(1000);
 }
}

void display_caps(uint8_t led_kbrd){
  static uint8_t displayed_led_kbrd = 0;

  if (displayed_led_kbrd != led_kbrd) {
     if (chMBPostTimeout(&display_mailbox, (msg_t) DISPLAY_TOGGLE_CAPS, TIME_IMMEDIATE)==MSG_OK){
       displayed_led_kbrd = led_kbrd;
     }
  }
}

void display_layer(layer_state_t state){
  state_display_layer=get_highest_layer(state);
  chMBPostTimeout(&display_mailbox, (msg_t) DISPLAY_TOGGLE_LAYER, TIME_IMMEDIATE);
}

void display_run_demo(uint32_t num_retr){
    demo_retr = num_retr;
    chMBPostTimeout(&display_mailbox, (msg_t) DISPLAY_DEMO_MODE, TIME_IMMEDIATE);
};
