
#define BOARD_HARDWARE_VERSION        "1.0.0"



#if defined(USE_WROVER_BOARD)


  #define BOARD_BUTTON_PIN            15                   
  #define BOARD_BUTTON_ACTIVE_LOW     true                 

  #define BOARD_LED_PIN_R             0                     
  #define BOARD_LED_PIN_G             2
  #define BOARD_LED_PIN_B             4
  #define BOARD_LED_INVERSE           false                 
  #define BOARD_LED_BRIGHTNESS        128                   

#else

  
  #define BOARD_BUTTON_PIN            0                     
  #define BOARD_BUTTON_ACTIVE_LOW     true                  

  #define BOARD_LED_PIN               4                    
                   
  #define BOARD_LED_INVERSE           false                 
  #define BOARD_LED_BRIGHTNESS        64                    

#endif




#define BUTTON_HOLD_TIME_INDICATION   3000
#define BUTTON_HOLD_TIME_ACTION       10000

#define BOARD_PWM_MAX                 1023

#define LEDC_CHANNEL_1     1
#define LEDC_CHANNEL_2     2
#define LEDC_CHANNEL_3     3
#define LEDC_TIMER_BITS    10
#define LEDC_BASE_FREQ     12000

#define CONFIG_AP_URL                 "blynk.setup"
#define CONFIG_DEFAULT_SERVER         "blynk.cloud"
#define CONFIG_DEFAULT_PORT           443

#define WIFI_NET_CONNECT_TIMEOUT      30000
#define WIFI_CLOUD_CONNECT_TIMEOUT    30000
#define WIFI_AP_CONFIG_PORT           80
#define WIFI_AP_IP                    IPAddress(192, 168, 4, 1)
#define WIFI_AP_Subnet                IPAddress(255, 255, 255, 0)


#define USE_TICKER

#define BLYNK_NO_DEFAULT_BANNER

#if defined(APP_DEBUG)
  #define DEBUG_PRINT(...) BLYNK_LOG1(__VA_ARGS__)
#else
  #define DEBUG_PRINT(...)
#endif
