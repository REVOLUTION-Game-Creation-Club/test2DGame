# Test2DGame

프로젝트 명: Test2DGame

목적 : WinApi 연습 및 각종 오픈소스 라이브러리를 활용한 2Dgame 제작 ( Ex: Legend of zelda , poketmonster )
      

기간 : 2015.05.05 ~ ( 현재 진행 중 )

사용언어 : C++/C

* 사용IDE : VS 2013 (community)
* 사용TOOL : tiled, etc..
* 사용 Lib : zlib, openal, box2d, tinyxml, etc ( 필요하다면 그때마다 관련 라이브러리 활용 )

* 2d tile set 을 활용한 tile base 게임.
* 현재 tiled 파일 포맷은 tmx parser를 구현, 그외 sprite 클래스 및 sprites packer & unpacker 제작을 목표로 하고있음.


p.s.  CustomSprite class 를 쓰지않고 ID3DXSprite를 쓰는 이유는 해당 클래스로는 2D게임을 만들 수 없을까? 하는
      작은 의문에서 시작했다. 사실, ID3DXSprite는 UI 목적으로 쓰이므로 가상카메라에 붙어서 직교투영 되므로 쓰기 불편한게
      있지만...그래도 뭐 실험정신으로!!
