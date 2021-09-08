VSCode 세팅하기
---
* VSCode 설치
* MinGW 다운로드 및 설치
   - https://sourceforge.net/projects/mingw/ 다운로드 및 실행
   - 아래 패키지 선택후 설치(`Installation > Apply Changes > 항목 선택후 Mark for installation`)
    mingw-developer-toolkit
    mingw32-base
    mingw32-gcc-g++
    msys-base
![image](https://user-images.githubusercontent.com/59942506/132453120-e001b92c-fe8e-4ea1-bb3c-8f05ea4caef0.png)
   - 환경변수 Path에 C:\MinGW\bin 추가
      - Win+R키로 실행 창을 열고 `sysdm.cpl` 실행 > `고급` 탭의 `환경변수` 선택 > 시스템 변수의 `Path`값을 편집하여 환경변수 추가
![image](https://user-images.githubusercontent.com/59942506/132453300-5f982c93-95a2-4d25-9046-20ac81669246.png)
* VSCode에 C/C++ 확장기능 설치
![image](https://user-images.githubusercontent.com/59942506/132453432-2f1893da-ee84-4477-a649-b27d602a4cda.png)
* 폴더 열기로 프로젝트 폴더를 선택(없으면 새로 만들기)
* 파일 추가 > cpp파일을 추가하고 코드 작성
* 터미널 메뉴 > Run Build Task 선택
![image](https://user-images.githubusercontent.com/59942506/132453560-d53b2f67-263c-46a9-ab60-b5500558395c.png)
   - g++.exe 활성 빌드 선택
![image](https://user-images.githubusercontent.com/59942506/132453626-083a8f9a-8346-44c8-ade6-d656701758b9.png)
* powershell 탭에서 실행해 정상 작동하는지 확인
![image](https://user-images.githubusercontent.com/59942506/132453756-802d9efd-d8f7-41b5-86e3-c97a3134598f.png)
