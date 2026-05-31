# 🔌 Smart Socket using ESP8266 + Blynk IoT + Siri

This project is a compact and practical smart socket built using the ESP8266 and Blynk IoT platform. It allows control of electrical devices through a mobile app and Apple Siri using Blynk APIs.

The entire system is enclosed in a compact box with a standard 3-pin socket, making it suitable for real-world use.

---

## 📺 Full Tutorial

👉 https://youtu.be/x8m7aeoN3rA

---

## ✨ Features

* Control appliances using the **Blynk mobile app**
* **Siri voice control** using Blynk APIs
* Real-time **state synchronization**
* Compact and enclosed design for safe usage

---

## 🧰 Components Used

### 1. ESP8266 D1 Mini

This is the main controller of the project. It connects to WiFi and communicates with the Blynk cloud to control the relay.

### 2. Hi-Link 5V 5W Power Supply

This module converts AC mains voltage (220V) to a stable 5V DC output, which powers the ESP8266 and relay module.

### 3. 5M05 Voltage Regulator

The 5M05 is used to ensure a stable 5V output and protect the circuit from voltage fluctuations.

### 4. 5V Relay Module (with Optocoupler)

The relay is used to switch the AC load (appliance).
The optocoupler provides electrical isolation between the high-voltage and low-voltage sides, improving safety.

### 5. 3-Pin Plug

Used to connect the smart socket to the main power supply.

### 6. 3-Pin Socket

This is where the appliance is connected. The relay controls the live line of this socket.

---

## ⚙️ How It Works

* The ESP8266 connects to WiFi and the Blynk cloud.
* When a command is sent from the app or Siri, the ESP8266 processes it.
* The relay is triggered accordingly to turn the connected appliance ON or OFF.
* The system keeps the app updated with the current state in real time.

---

## 📱 Blynk Setup

1. Create a template in Blynk IoT.
2. Add a **Button Widget**.
3. Set:

   * Virtual Pin: **V0**
   * Mode: **Switch**
4. Copy your **Auth Token, Template ID, and Template Name** into the code.

---

## 🚀 Getting Started

1. Install Arduino IDE.
2. Install ESP8266 board support.
3. Install the **Blynk IoT library**.
4. Update WiFi and Blynk credentials in the code.
5. Upload the code to ESP8266 D1 Mini.
6. Power the device and test using the app.

---

## ⚠️ Important Notes

* The relay used is **active LOW**
  (LOW = ON, HIGH = OFF)
* Be careful while working with **AC mains voltage**
* Always ensure proper insulation and enclosure

---

## 👨‍💻 Author

Made by **iOT India YouTube Channel**
