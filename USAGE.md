# USAGE

## MPLABX

### Load Project

File -> Open Project

Select

`./MPLABX/firmware/ATMEL_SAM_L10_Dev.X`

## MPLAB® Harmony Configurator v3

## Load settings

### Launch MHC

Tools -> Embedded -> MPLAB@ Harmony 3 Configurator

Harmony 3 Configuratorが正しく読み込まれていれば, 以下のような画面が現れる.

<div align="center"><img src="img/mhc3.png" width="80%" alt="mhc3"></div>

各Periheralをクリックすると右側に設定画面が現れるので, 各自設定していく.

### Close MHC

MHC -> Exit

## Generate Code

MHC -> Generate Code

## MHC Settings

### System Settings

<div align="center"><img src="img/system.png" width="60%" alt="system"></div>

Ports -> Use PORT PLIBをTQFP32に変更する.(Pin Tableからも変更可能.) パッケージの変更を行うとピンの設定が初期化されるので初めに行うことをおすすめする.

Processor clockを使ってdelay(SYSTICK_DelayMs)を使用する場合はSysTickの設定をする.

コード生成の設定などもSystemに集約されているので一度全体に目を通しておくことをお勧めする.

### Clock Settings

クロックの設定を行う.

MHC -> Tools -> Clock Configuration

基本的には初期設定のまま.

![clock](img/clock.png)

水晶を用いてRTCを使用する場合は以下の設定をする.

- 32KHz Oscillator Controller(Advanced Settings) -> 32KHz External Crystal Oscillator(XOSC32k) Enable：Enable
- 32KHz Oscillator Controller(Advanced Settings) -> Enable 32KHz Output：Enable
- RTC Clock Selection：XOSC1K

### DMA Settings

DMAの設定を行う.

MHC -> Tools -> DMA Configuration

![dma](img/dma.png)

### NVIC Settings

割り込みの設定を行う.

<div align="center"><img src="img/nvic.png" width="60%" alt="nvic"></div>

割り込みの優先順位を一括で管理する.

### Pin Settings

ピンの設定を行う.

MHC -> MHC -> Pin Configuration

以下のピン設定を行う. 設定を変更するピンのみ記載. (-：設定不可)

|No.|Pin ID|Custom Name    |Function       |Mode    |Direction|Latch|Pull Up|Pull Down|Drive Strength|
|:--|:--   |:--            |:--            |:--     |:--      |:--  |:--    |:--      |:--           |
|3  |PA02  |               |DAC_VOUT       |Analog  |-        |-    |-      |-        |-             |
|4  |PA03  |               |ADC_AIN1       |Analog  |-        |-    |-      |-        |-             |
|8  |PA07  |LED            |GPIO           |Digital |Out      |-    |-      |-        |-             |
|17 |PA16  |               |SERCOM1_PAD0   |Digital |-        |-    |-      |-        |-             |
|18 |PA17  |               |SERCOM1_PAD1   |Digital |-        |-    |-      |-        |-             |
|23 |PA24  |               |SERCOM0_PAD2   |Digital |-        |-    |-      |-        |-             |
|24 |PA25  |               |SERCOM0_PAD3   |Digital |-        |-    |-      |-        |-             |
|25 |PA27  |               |EIC_EXTINT5    |-       |-        |-    |Enable |-        |-             |
|31 |PA30  |               |TC1_WO0        |Digital |-        |-    |-      |-        |-             |
|32 |PA31  |               |TC1_WO1        |Digital |-        |-    |-      |-        |-             |

設定後のピンの状態.

<div align="center"><img src="img/pin.png" width="60%" alt="pin"></div>

## Main

MHC3でコード生成されるmainファイルをNo.0とする. 以降, 機能を追加していくたびにmainファイルを別で生成する.

デバッグの際は, mainファイルを切り替えて使用する. 基本的には上から順に動作確認することを前提とする.

|No.|Program File                                           |Description                      |
|:--|:--                                                    |:--                              |
|0  |[main.c](MPLABX/firmware/src/main.c)                   |default                          |
|1  |[main_gpio.c](MPLABX/firmware/src/main_gpio.c)         |Digital Out, Digital In          |
|2  |[main_delay.c](MPLABX/firmware/src/main_delay.c)       |Delay Function                   |
|3  |[main_timer.c](MPLABX/firmware/src/main_timer.c)       |Timer Function(on TC0)           |
|4  |[main_rtc.c](MPLABX/firmware/src/main_rtc.c)           |Real Time Clock Function         |
|5  |[main_eic.c](MPLABX/firmware/src/main_eic.c)           |External Interrupt Function      |
|6  |[main_usart.c](MPLABX/firmware/src/main_usart.c)       |USART(on SERCOM0)                |
|7  |[main_stdio.c](MPLABX/firmware/src/main_stdio.c)       |Stnadard IO Function             |
|8  |[main_adc.c](MPLABX/firmware/src/main_adc.c)           |ADC Function                     |
|9  |[main_dac.c](MPLABX/firmware/src/main_dac.c)           |DAC Function                     |
|10 |[main_pwm.c](MPLABX/firmware/src/main_pwm.c)           |PWM Function(on TC1)             |

## Peripheral Settings

### 1 GPIO

基板のUSER BUTTONを押すと, USER LEDが点灯するサンプル.

PA15の設定のみ変更し, コード生成を行う. 初期では状態変化割り込みとしているが汎用の入力ピンに変更するため.

|No.|Pin ID|Custom Name    |Function       |Mode    |Direction|Latch|Pull Up|Pull Down|Drive Strength|
|:--|:--   |:--            |:--            |:--     |:--      |:--  |:--    |:--      |:--           |
|25 |PA27  |BUTTON         |GPIO           |-       |In       |-    |Enable |-        |-             |

他のサンプルを試す場合は元に戻す.

### 2 Delay

Systickを利用したDelay関数で100msのタイマーを作成し, LEDをToggleさせる.

### 3 Timer

Available Components -> Periherals -> TC -> TC0を選択.

TC0を利用した100msのタイマーを作成し, LEDをToggleさせる.

TC0を以下のように設定する.

<div align="center"><img src="img/tc0.png" width="60%" alt="tc0"></div>

### 4 RTC

Available Components -> Periherals -> TC -> RTCを選択.

RTCを利用した1sのタイマーを作成し, LEDをToggleさせる.

RTCを以下のように設定する.

<div align="center"><img src="img/rtc.png" width="60%" alt="rtc"></div>

### 5 EIC

Available Components -> Periherals -> EIC -> EICを選択.

状態変化割り込みでボタンの変化を読み取る.

EICを以下のように設定する.

<div align="center"><img src="img/eic.png" width="60%" alt="eic"></div>

### 6 SERCOM UART

Available Components -> Periherals -> SERCOM -> SERCOM0を選択.

SERCOM0をUSARTに設定し, TermianlでSerialデバッグをする.

SERCOM0を以下のように設定する.

<div align="center"><img src="img/sercom0.png" width="60%" alt="sercom0"></div>

Terminalで確認する.

### 7 SERCOM printf

Available Components -> Tools-> STDIOを選択.

printfのputc, getcをSERCOM0にリダイレクトするように設定する.

SERCOM0とSTDIOのUARTピンをそれぞれ接続する.

<div align="center"><img src="img/stdio.png" width="40%" alt="stdio"></div>

### 8 ADC

Available Components -> Periherals -> ADC -> ADCを選択.

MHC -> MHC -> ADC Configurationを選択.

PA03をADC入力(AIN1)として使用する. ADC Configurationを以下のように設定する.

![adc1](img/adc1.png)

ADCを以下のように設定する.

<div align="center"><img src="img/adc2.png" width="60%" alt="adc2"></div>

### 9 DAC

Available Components -> Periherals -> DAC -> DACを選択.

DACを以下のように設定する.

<div align="center"><img src="img/dac.png" width="60%" alt="dac"></div>

### 10 PWM

Available Components -> Periherals -> TC -> TC1を選択.

TC1を以下のように設定する.  PWM周波数：1kHz, 初期Duty：50%に設定.

<div align="center"><img src="img/tc1.png" width="60%" alt="tc1"></div>
