#include<ESP8266WiFi.h>
#include <ArduinoJson.h>
#include"SPI.h"
const char* ssid = "iPhone"; // 자신의 환경에 맞는 무선 인터넷의 SSID
const char* password= "a16506725!@"; // 와 패스 워드를 입력합니다.

String city="Seoul";
String apiURI = "http://api.openweathermap.org/data/2.5/weather";
String queryString="?q="+city+"&appid="+"4b80fc041e45e18cadb4bbd921e529f8";

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(115200);  //시리얼 모니터 사용하기 위해 초기화

  WiFi.begin(ssid, password); // WiFi  시작 초기화  가 되면  다음으로 넘어갑니다.

  Serial.println();
  Serial.print("Connecting"); //  WiFi 에 연결중  "Connecting "출력

  while(WiFi.status() != WL_CONNECTED)
   {
    delay(500);
    Serial.print("."); //연결될때 까지 출력
   }

   Serial.println("success!");  //연결이 완료되면..
   Serial.print("IP Address is: ");
   Serial.println(WiFi.localIP());   // 연결된 아이피가 출력됩니다.
}

void loop() {
  // put your main code here, to run repeatedly:
}








/*var apiURI = "http://api.openweathermap.org/data/2.5/weather?q="+city+"&appid="+"4b80fc041e45e18cadb4bbd921e529f8";
        $.ajax({
            url: apiURI,
            dataType: "json",
            type: "GET",
            async: "false",
            success: function(resp) {
                console.log(resp);
                console.log("현재온도 : "+ (resp.main.temp- 273.15) );
                console.log("현재습도 : "+ resp.main.humidity);
                console.log("날씨 : "+ resp.weather[0].main );
                console.log("상세날씨설명 : "+ resp.weather[0].description );
                console.log("날씨 이미지 : "+ resp.weather[0].icon );
                console.log("바람   : "+ resp.wind.speed );
                console.log("나라   : "+ resp.sys.country );
                console.log("도시이름  : "+ resp.name );
                console.log("구름  : "+ (resp.clouds.all) +"%" );                 
            }
        })
    }*/


//날씨 분류 
void weatherpixel(){
   float rantime = random(20,50);
   //날씨 코드가 200부터 531까지 범위 안에 있다면 type3 패턴으로 led를 제어한다.
   //비, 눈, 우박
  if(weather>199 && weather<532){   
    type3();
  }
  else ;

   //날씨 코드가 701부터 781, 또는 802부터  804까지 범위 안에 있다면 type2 패턴으로 led를 제어한다.
   //흐림
  if(weather>700 && weather <782){
    type2();
  }
  else ;
  if(weather>801 && weather<805){
    type2();
  }
  else ;
  
  //날씨 코드가 800부터 801
  //흐림
  if(weather>799 && weather<802){   
     type1();
   }
   else ;
}

//LED 제어


void type1(){
  rainbow(15);
  }

void type2(){

// 하얀색 불빛이 서서히 켜지고, 꺼진다.

   uint16_t i, j;
  for(j=0; j<256; j+=1) {
    for(i=0; i       int sum = i+j;
      map(sum,0,300,120,190);
     strip.setPixelColor(i, Wheel(sum),Wheel(sum),Wheel(sum));

    }
    strip.show();
    delay(10);
  }


}

void type3(){

//노란색 불빛이 서서히 켜지고, 꺼짐을 1회에서 4회 정도 무작위 반복한 후 깜빡인다.
 uint16_t i, j,q;
 for(q=0; q   for(j=0; j<256; j+=1) {
    for(i=0; i       int sum = i+j;
      map(sum,0,300,120,190);
     strip.setPixelColor(i, Wheel(sum),Wheel(sum),0);

    }
    strip.show();
    delay(10);
  }
 }
    theaterChase(strip.Color(255, 255, 0), 60); //흰색 출력 
}
