# Dự án Đèn Thông Minh Điều Khiển Qua App Điện Thoại

Dự án này là một hệ thống đèn thông minh cho phép bật tắt đèn thông qua ứng dụng điện thoại. Đèn 220V được điều khiển thông qua ESP32 kết nối tới WiFi.

## Tính năng

- Bật tắt đèn thông qua điện thoại
- Đèn 220V được điều khiển thông qua ESP32 kết nối tới WiFi
- Giao diện ứng dụng điện thoại thân thiện
- Bật tắt và hiển thị trạng thái đèn theo thời gian thực

## Công nghệ sử dụng

- Java và Android Studio để viết ứng dụng điện thoại
- C++ và Arduino IDE để viết code điều khiển cho ESP32
- Google Firebase để sử dụng cơ sở dữ liệu thời gian thực

## Phần cứng sử dụng

- ESP32
- Đèn LED 220V
- Relay 5V

## Cách sử dụng

1. Clone lại repository:
    ```sh
    git clone https://github.com/LaGGer287/SMART_LED.git
    ```

2. Di chuyển đến thư mục dự án:
    ```sh
    cd SMART_LED
    ```

3. Cài đặt các thư viện cần thiết:
    - Mở Arduino IDE
    - Vào `Sketch` -> `Include Library` -> `Manage Libraries...`
    - Tìm và cài đặt các thư viện cần thiết cho ESP32

4. Kết nối ESP32 với máy tính và chọn cổng COM.

5. Vào folder LED, mở file `.ino` trong Arduino IDE và đẩy mã vào ESP32.

6. Kết nối ESP32 với đèn LED 220V thông qua Relay 5V.

7. Cài đặt ứng dụng điện thoại trên Android Studio:
    - Mở Android Studio
    - Import dự án từ thư mục `Mobile_App`
    - Kết nối với Firebase bằng cách thêm tệp `google-services.json` vào dự án

8. Tạo Realtime Database trên Firebase:
    - Vào [Firebase Console](https://console.firebase.google.com/)
    - Chọn dự án của bạn hoặc tạo dự án mới
    - Chọn `Database` trong menu bên trái
    - Chọn `Create Database`e`
    (Vào folder Firebase để xem)
9. Thay đổi tên và mật khẩu WiFi trong phần kết nối WiFi của ESP32 và phần `FIREBASE_AUTH` và `FIREBASE_HOST` trong mã kết nối tới Firebase:
    ```cpp
    // Thay đổi tên và mật khẩu WiFi
    const char* ssid = "YOUR_WIFI_SSID";
    const char* password = "YOUR_WIFI_PASSWORD";

    // Thay đổi thông tin Firebase
    #define FIREBASE_HOST "YOUR_FIREBASE_HOST"
    #define FIREBASE_AUTH "YOUR_FIREBASE_AUTH"
    ```

10. Chạy ứng dụng điện thoại từ Android Studio.

11. Kiểm tra kết nối giữa ứng dụng điện thoại và ESP32 qua Firebase Realtime Database.

12. Sử dụng ứng dụng điện thoại để bật tắt đèn và xem trạng thái theo thời gian thực.

**Lưu ý:** Vì đây là đèn 220V nên hãy cẩn thận không được chạm vào Relay để tránh bị giật.

Chúc bạn sử dụng dự án thành công!
