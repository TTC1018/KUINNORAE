# (2019) KUINNORAE 쿠인노래방 (코인노래방 키오스크)


## 개요

C++, Qt를 활용한 유사 노래방 키오스크 프로그램 구현


## 개발 참여원

[@ttc1018](https://github.com/ttc1018) - 작동 로직 구현 및 이미지 소스 제작 <br/>
[@ChanwooAn](https://github.com/ChanwooAn) - 작동 로직 구현 <br/>


## 배포 파일

[실행파일 다운로드](https://github.com/TTC1018/KUINNORAE/raw/main/KUINNORAE_executable.zip)


## 기능

1. 회원가입 (전화번호로 가입)
2. 회원정보 확인 (잔여 곡 확인)
3. 방 선택
4. 곡 충전
5. 곡 사용 (사용시 일정 시간마다 자동차감으로 구현)
6. 사용 중단 (미 사용 곡 저장)
7. 관리실 연락처 확인
8. 방 이용 현황 표시
9. 예상 대기시간 확인


## 0. 메인화면

![메인화면](https://user-images.githubusercontent.com/39405316/167876499-42a4cb88-e27d-4649-8a28-343fac2a3706.png)


키오스크 프로그램을 통해 노래방의 구조를 확인할 수 있도록, 노래방의 구조와 유사하게 UI를 구성하였음 <br/>
또한 본 프로그램은 어디까지나 유사 키오스크 프로그램이고, <br/>
윈도우에서 실행되기 때문에 키오스크 프로그램에 가까운 느낌을 주도록 프로그램 테두리는 숨겼음. (Alt + F4로 창 종료 가능) <br/>

## 1. 회원가입

![회원가입_1](https://user-images.githubusercontent.com/39405316/167877475-219b0056-fbd7-4762-b13c-6e5b846679a3.png) <br/>
![회원가입_2](https://user-images.githubusercontent.com/39405316/167877659-83ffc630-d9c2-4044-a964-598088ff71b7.png) <br/>
![회원가입_3](https://user-images.githubusercontent.com/39405316/167878208-f0aef260-e368-42f6-abab-33a23344c33b.png) <br/>

우측 상단 회원가입 버튼을 눌러 사용 가능. <br/>
전화번호 형식의 아이디를 강제하였으며, 11자리 전화번호를 입력하면 자동으로 비밀번호 칸으로 초점이 넘어감. <br/>
비밀번호를 지우면 다시 전화번호 칸으로 초점이 돌아옴. <br/>
ID 중복체크 기능 있음.

## 2. 회원정보 확인

![회원정보_1](https://user-images.githubusercontent.com/39405316/167878825-8cb8ecc4-8fca-41a9-848f-ba133764ed50.png)
![회원정보_2](https://user-images.githubusercontent.com/39405316/167878984-f04d448f-dfcf-41cb-927e-abcc090e1d99.png)


우측 상단 회원정보 버튼을 눌러 사용 가능. <br/>
존재하는 계정을 입력하여 로그인 시에, 잔여곡을 확인할 수 있음.

## 3. 방 선택

![방선택_1](https://user-images.githubusercontent.com/39405316/167880283-0d088aef-d3a9-4aff-8d11-e5e60d1af9f3.png)
![방선택_2](https://user-images.githubusercontent.com/39405316/167880294-4a5733a0-bf89-467a-9532-e2af5bf3f792.png)


아무 빈 방이나 클릭하면 방의 상태가 바뀌며 로그인 창 출현. <br/>
계정 정보를 입력하여 로그인 하면 충전/사용 창으로 바뀜.

## 4. 곡 충전

![곡충전_1](https://user-images.githubusercontent.com/39405316/167881093-0d0c0135-0b36-4e12-8448-e0167d0db31f.png)


방 선택 창 좌측 하단의 충전 버튼을 누르면 사용 가능. <br/>
원하는 곡 수를 선택하여 결제가 가능함. <br/>
(결제는 따로 되었다는 가정하에 구현)

## 5. 곡 사용

![곡사용_1](https://user-images.githubusercontent.com/39405316/167881555-076962b6-c074-4b68-8e42-4d54a2cd2d3d.png)
![곡사용_2](https://user-images.githubusercontent.com/39405316/167881879-c2860159-5024-46b3-8157-0353391fe3a2.png)


방 선택 창 우측의 숫자패드를 이용하여 사용할 만큼의 곡 수를 입력. <br/>
자신이 가진 곡 수 이상을 입력하면 사용되지 않음. <br/>
사용 조건을 충족하면 방의 상태가 붉게 변하며, 방 이용 현황에 갱신됨. <br/>
본 프로젝트는 키오스크 유사 프로그램 구현이 목적이므로, 곡 수는 스레드가 일정 시간마다 1곡씩 차감하도록 프로그래밍 하였음.

## 6. 사용 중단

![곡저장_1](https://user-images.githubusercontent.com/39405316/167882423-ebd5720f-af35-4bfd-8a96-a84f3e0b2152.png)

사용 중인 방을 클릭하고, 비밀번호를 입력하면 잔여 곡이 차감되지 않고 저장됨.

## 7. 관리실 연락처 확인

![관리자연락처](https://user-images.githubusercontent.com/39405316/167884565-0661f6b3-cff4-406d-b2ec-1d9e4c880dd4.png)


우측 하단 관리실 연락처 버튼을 통해 관리자 연락처 확인 가능. (소스 코드에서 수정 가능함)

## 8. 방 이용 현황 표시

![방이용현황_1](https://user-images.githubusercontent.com/39405316/167883448-3ab3765b-c938-489f-97c0-136ebfbe1e6d.png)


현재 사용 중인 방의 수가 기록되어, 우측 하단 패널에 출력해줌.

## 9. 예상 대기시간 확인

![예상대기시간확인](https://user-images.githubusercontent.com/39405316/167884309-e7745f86-46e9-48c2-81b7-b40b393f750e.png)


모든 방이 사용 중일 때, 각 방의 잔여곡을 확인하고 예상 시간을 계산(곡 당 3분)하여 우측 하단 패널에 출력해줌. 
