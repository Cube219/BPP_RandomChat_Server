# BPP_RandomChat_Server

프로그래밍기초와실습 수업과제물인 랜덤채팅 서버입니다. (Random chatting server that is a Basis and Practice in Programming lecture assignment.)

## 실행 방법 (How to Run)

## 구조 (Structure)

* **MainServer.cpp**
  * 서버의 코어 부분.  
    (A core in server.)
  * 클라이언트의 접속을 받아들이기, 유저 매칭 등 주요 역할을 한다.  
    (Has an important role to accept client's connection, match the users, etc.)
* **ConnectedClient.cpp**
  * 연결된 클라이언트의 정보를 담고 있는 클래스.  
    (A class that has an information of connected client.)
* **Room.cpp**
  * 랜덤으로 매칭된 유저들이 들어가있는 방에 관한 클래스.  
    (A class about a room having the users matched randomly.)
* **Protocol.cpp**
  * 서버와 클라이언트 사이의 프로토콜에 관한 클래스.  
    (A class about a protocol between server and client.)

## 사용한 라이브러리 (Using Library)