# USAGE

## MPLAB® Harmony Configurator v3

## Load settings

### Launch MHC

Tools -> Embedded -> MPLAB@ Harmony 3 Configurator

### Close MHC

MHC -> Exit

## Generate Code

MHC -> Generate Code

## MHC Settings

### System Settings

### Clock Settings

クロックの設定を行う.

MHC -> Tools -> Clock Configuration

基本的には初期設定のまま.

### DMA Settings

DMAの設定を行う.

MHC -> Tools -> DMA Configuration

### NVIC Settings

割り込みの設定を行う.

### Pin Settings

ピンの設定を行う.

MHC -> MHC -> Pin Configuration

以下のピン設定を行う. 設定を変更するピンのみ記載. (-：設定不可)

|No.|Pin ID|Custom Name    |Function       |Mode    |Direction|Latch|Pull Up|Pull Down|Drive Strength|
|:--|:--   |:--            |:--            |:--     |:--      |:--  |:--    |:--      |:--           |

設定後のピンの状態.

## Main

MHC Settingsを起こった時点でコード生成したmainファイルをNo.0とする. 以降, 機能を追加していくたびにmainファイルを別で生成する.

デバッグの際は, mainファイルを切り替えて使用する. 基本的には上から順に動作確認することを前提とする.

|No.|Program File                                           |Description                      |
|:--|:--                                                    |:--                              |
|0  |[main.c](MPLABX/firmware/src/main.c)                   |default                          |
|1  |[main_gpio.c](MPLABX/firmware/src/main_gpio.c)         |Digital Out, Digital In          |
|2  |[main_delay.c](MPLABX/firmware/src/main_delay.c)       |Delay Function                   |
|3  |[main_timer.c](MPLABX/firmware/src/main_timer.c)       |Timer Function(on TC3)           |
|4  |[main_rtc.c](MPLABX/firmware/src/main_rtc.c)           |Real Time Clock Function         |
|5  |[main_eic.c](MPLABX/firmware/src/main_eic.c)           |External Interrupt Function      |
|6  |[main_sercom3.c](MPLABX/firmware/src/main_sercom3.c)   |USART(on SERCOM3)                |
|7  |[main_stdio.c](MPLABX/firmware/src/main_stdio.c)       |Stnadard IO Function             |
|8  |[main_adc.c](MPLABX/firmware/src/main_adc.c)           |ADC Function                     |
|9  |[main_dac.c](MPLABX/firmware/src/main_dac.c)           |DAC Function                     |
|10 |[main_pwm.c](MPLABX/firmware/src/main_pwm.c)           |PWM Function(on TC4)             |
|11 |[main_iic.c]                                           |I2C(on SERCOM4)                  |

## Peripheral Settings

### 1 GPIO

基板のUSER BUTTONを押すと, USER LEDが点灯するサンプル.

PA15の設定のみ変更し, コード生成を行う. 初期では状態変化割り込みとしているが汎用の入力ピンに変更するため.

他のサンプルを試す場合は元に戻す.

### 2 Delay

Systickを利用したDelay関数で100msのタイマーを作成し, LEDをToggleさせる.

### 3 Timer

### 4 RTC

Available Components -> Periherals -> TC -> RTCを選択.

RTCを利用した1sのタイマーを作成し, LEDをToggleさせる.

RTCを以下のように設定する.

### 5 EIC

Available Components -> Periherals -> EIC -> EICを選択.

状態変化割り込みでボタンの変化を読み取る.

EICを以下のように設定する.

### 6 SERCOM UART

### 7 SERCOM printf

### 8 ADC

Available Components -> Periherals -> ADC -> ADCを選択.

MHC -> MHC -> ADC Configurationを選択.

### 9 DAC

Available Components -> Periherals -> DAC -> DACを選択.

### 10 PWM

### 11 I2C
