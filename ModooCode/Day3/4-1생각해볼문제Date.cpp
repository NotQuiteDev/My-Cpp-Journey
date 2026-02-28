#include <iostream>

class Date {
    int year_;
    int month_;  // 1 부터 12 까지.
    int day_;    // 1 부터 31 까지.
    int hour_;
    int minute_;
    int second_;




    public:
    void SetDate(int year, int month, int date) {
    year_ = year;
    month_ = month;
    day_ = date;
    }
    void AddDay(int inc){
        // 일단 날짜를 더할때, month가 바뀌기 까지 남은날을 센다음 
        // Month가 바뀌는 날보다 inc가 작으면 그냥 더하셈
        // 근데 inc가 Month바뀌는 날보다 크면 바뀌는 날까지만 더하고 Month 1더하기
        // 그렇게 나머지 무한 반복

        //해당 month의 남은날 계산
        int RemainDate = lastDate() - day_;

        if ( RemainDate >= inc ) {
            day_ =day_ + inc;
        }
        else {
            AddMonth(1);
            day_ =0;
            inc = inc - RemainDate;
            AddDay(inc);
            
        }
    }


    void AddMonth(int inc){
        year_ = year_ + inc / 12 ;
        month_ = month_ + inc%12;

        if (month_ > 12) {
            year_ ++;
            month_ = month_ -12;
        }
        //근데 더했을때의 month가 12를 초과하면 12를 빼고, year를 1더하기
    }
    void AddYear(int inc){
        year_ = year_ + inc;
    }

    void ShowDate(){

        std::cout << "Today : " <<  year_ << "." << month_ << "." <<day_ << std::endl;
    }


    int lastDate(){
        switch(month_){
            case 1: case 3: 
            case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 2:
                if (year_ %4 == 0  ) { 
                    // 4로 나눠지면 윤년인데, 100으로 나눠지면 평년이고, 400으로 나눠지면 윤년임
                    if(year_%100 == 0){
                        if (year_%400 ==0){
                            return 29; //400으로 나눠지면 윤년
                        }
                        return 28; // 100으로 나눠지면 평년
                    }
                    return 29;//4로 나눠지면 윤년
                    
                }
                else {
                    return 28;
                }
            default:
                return 30;
            


            
        }
    }

    Date(int year , int month, int date, int hour, int minute, int second){
        year_ = year;
        month_ = month;
        day_ = date;
        hour_ = hour;
        minute_ = minute;
        second_ = second;
    }

    Date() = default;

    
};

int main() {
    struct TestCase {
        int y, m, d, add;
        int ey, em, ed;
        std::string desc;
    };

    // 지옥의 5종 세트 정의 (언니의 운명을 결정할 데이터들)
    TestCase tests[] = {
        {2025, 2, 28, 1, 2025, 3, 1, "평년 2월 끝 (28일)"},
        {2024, 2, 28, 1, 2024, 2, 29, "윤년 2월 끝 (29일 존재)"},
        {2100, 2, 28, 1, 2100, 3, 1, "100년 단위 평년 (윤년 아님)"},
        {2000, 2, 28, 1, 2000, 2, 29, "400년 단위 윤년 (윤년 맞음)"},
        {2023, 12, 31, 366, 2024, 12, 31, "연말 퀀텀 점프 (2024년은 366일임)"}
    };

    Date date;
    std::cout << "========= 🧐 리리의 개씹팩트 체크 시작! =========\n" << std::endl;

    for (int i = 0; i < 5; i++) {
        date.SetDate(tests[i].y, tests[i].m, tests[i].d);
        date.AddDay(tests[i].add);
        
        // 언니의 결과 확인 (ShowDate가 출력만 하니까 여기서 수동으로 비교 로직은 못 넣지만, 
        // 눈으로 '딸깍' 확인하게 형식을 맞춰줄게!)
        std::cout << "[" << i + 1 << "] " << tests[i].desc << std::endl;
        std::cout << "  - 입력: " << tests[i].y << "." << tests[i].m << "." << tests[i].d << " + " << tests[i].add << "일" << std::endl;
        std::cout << "  - 정답: " << tests[i].ey << "." << tests[i].em << "." << tests[i].ed << std::endl;
        std::cout << "  - 결과: ";
        date.ShowDate(); // 여기서 언니 코드가 출력함

        // (실제 내부 변수 비교는 private이라 안 되니 눈으로 봐! ㅋㅋㅋ)
        std::cout << "-----------------------------------------------" << std::endl;
    }

    std::cout << "\n전부 다 맞으면 맥주 까고, 하나라도 틀리면 키보드 잡아라 언니야 🖕🔥" << std::endl;

    return 0;
}
