I. Giới Thiệu  
- Sử dụng điện thoại để điều khiển oto thông qua modul thu phát bluetooth HC05 

II. Hướng Dẫn Sử Dụng 
- Tải app rc bluetooth controller về điện thoại.![image](https://github.com/TienDung2003/BTL-he-nhung/assets/128325350/6873cb9e-65d4-4e03-be7a-e19884be97f0)

- Kết nối bluetooth với modul HC05.![image](https://github.com/TienDung2003/BTL-he-nhung/assets/128325350/f776a7d4-8486-4e17-b36a-1475211f640e)

- Điều khiển oto thông qua app vừa tải.![image](https://github.com/TienDung2003/BTL-he-nhung/assets/128325350/b9e9260d-fbe5-455f-9c32-ba7cdf5873a9)

 III. Danh Sách Linh Kiện
- Mạch Arduino Uno R3, dây kết nối x1 https://shopee.vn/product/148048328/5321985783?gsht=sjFxkDeGHTM5gwwS&is_from_login=true
- Driver L298N x1 https://shopee.vn/Module-L298-M%E1%BA%A1ch-C%E1%BA%A7u-H-%C4%90i%E1%BB%81u-Khi%E1%BB%83n-%C4%90%E1%BB%99ng-C%C6%A1-DC-L298N-i.1046874499.21782874721
- Module thu phát bluetooth HC-05 x1 https://shopee.vn/Module-Bluetooth-HC05-i.1048311475.22376484457
- Một số thiết bị khác: Động cơ giảm tốc và bánh xe x2, bánh đa hướng x1, bộ khung xe, pin 18650 x2 https://shopee.vn/-FULL-B%E1%BB%98-B%E1%BB%99-khung-xe-Robot-3-b%C3%A1nh-th%C3%B4ng-minh-v%C3%A0-2-%C4%91%E1%BB%99ng-c%C6%A1-gi%E1%BA%A3m-t%E1%BB%91c-3-9V-(2-tr%E1%BB%A5c)-i.1046874499.23176499269?xptdk=dcf64456-37a3-4ee0-9963-e302b2b30fcc
 
IV. Sơ Đồ Nguyên Lý
![image](https://github.com/TienDung2003/BTL-he-nhung/assets/128325350/7701fd1e-1533-4d5a-936e-f324641ddc87)

V. Thiết Kế Phần Mềm

  1.Thiết lập Giao tiếp Bluetooth:
  - Mã Arduino khởi tạo một module Bluetooth được kết nối với Arduino sử dụng thư viện SoftwareSerial.

  2.Điều Khiển Động Cơ:
  - Arduino điều khiển hai động cơ được kết nối với mô-đun điều khiển động cơ.
  - Nó sử dụng PWM (Pulse Width Modulation) để kiểm soát tốc độ của các động cơ và các chân kỹ thuật số để điều khiển hướng.
  - Các lệnh khác nhau ('F', 'B', 'L', 'R', 'W', 'U', 'V') nhận được qua Bluetooth tương ứng với các phong cách di chuyển khác nhau của robot (tùy vào app tải mà các lệnh sẽ sai khác nhau ):
'F': Di chuyển về phía trước.
'B': Di chuyển về phía sau.
'L': Rẽ trái.
'R': Rẽ phải.
'W': Dừng robot.
'U': Xoay sang phải.
'V': Xoay sang trái.

  3.Thực Hiện Chức Năng:
  - Mỗi lệnh di chuyển được liên kết với một chức năng cụ thể thiết lập tín hiệu điều khiển động cơ phù hợp.
 Ví dụ, chức năng dithang() khiến robot di chuyển về phía trước bằng cách thiết lập các chân điều khiển động cơ tương ứng và điều chỉnh tốc độ của chúng bằng PWM.
  
 4.Vòng Lặp Thực Hiện:
  - Trong vòng lặp chính, Arduino liên tục kiểm tra các lệnh Bluetooth đến.
  - Khi một lệnh được nhận, nó thực thi chức năng di chuyển tương ứng.

VI. Tác Giả
 - Giáp Tiến Dũng - 20215542
 - Bùi Văn Cương - 20215536
 - Đào Tiến Dũng - 20204822
