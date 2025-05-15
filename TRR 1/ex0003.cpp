/*

MẸO CODE CÓ DFS HAY ĐÊJ QUY TA NÊN NHỚ 1 QUY TẮC ĐÓ LÀ 
KHI TA VẼ CÂY ĐỆ QUY RA THÌ MỖI NÚT TƯƠNG ỨNG VỚI 1 HÀM LUÔN 

ĐIỀU NÀY RẤT CÓ LỢI BỞI LẼ NÓ SẼ GIÚP CHÚNG TA BIẾT CHÍNH XÁC HƠN MÌNH ĐANG LÀM GÌ 
VỚI MỖI 1 NÚT HAY GỌI LÀ T HÀM THÔNG TIN 

CHÚ Ý : ĐIỀU RẤT QUAN TRỌNG KHI CODE ĐỆ QUY KHÔNG BỊ NHẬM ĐÓ LÀ 
MỖI HÀM HÃY TƯỞNG TƯỢNG ĐÓ LÀ 1 NÚT THÔNG TIN, TA CÓ KHI ĐÓ TA TRUYỀN THÔNG TIN VÀO 
HÀM ĐÓ NHƯ KHI TA NHÁP RA GIẤY VẬY ĐIỀU ĐÓ SẼ KHIẾN CODE CỦA RA RẤT ÍT KHI BỊ NHẦM 

CHÚ Ý : ĐIỀU RẤT QUANG TRỌNG KHI CODE ĐỆ QUY KHÔNG BỊ NHẦM ĐÓ LÀ 
MỖI HÀM HÃY TƯỞNG TƯỢNG ĐÓ LÀ 1 NÚT THÔNG TIN, TA CÓ KHI ĐÓ TA TRUYỀN THÔNG TIN VÀO HÀM ĐÓ 
NHƯ KHI TA NHÁP RA GIẤY MỖI NÚT CỦA NÓ CHỨA THÔNG TIN GÌ ĐIỀU ĐÓ SẼ KHIẾN CODE CỦA TA RẤT ÍT KHI BỊ NHẦM 


CHÚ Ý : ĐIỀU RẤT QUAN TRỌNG KHI CODE DỆ QUY KHÔNG BỊ NHÀMAA ĐÓ LÀ 
MỖI HÀM HÃY TƯỞNG TƯỢNG ĐÓ LÀ 1 NÚT THÔNG TIN, TA CÓ KHI ĐÓ TA TRUYỀN THÔNG TIN VÀO HÀM ĐÓ 
NHƯ KHI TA NHÁP RA GIẤY HÀM ĐÓ SẼ ĐƯỢC TRUYỀN LÀ NÓ SẼ CHỨA THÔNG TIN GÌ KHI ĐỆ QUY 


VÍ DỤ 


        BACKTRACK(A, B, C, D) THÌ SAU ĐÓ CÁC BIẾN A, B, C, D TA KHÔNG NÊN XỬ LÝ MÀ TA NÊN TRUYỀN GIÁN TIẾP 
        VÀO VÍ DỤ 
            KHÔNG NÊN A += 1, B += 2.... SAU ĐÓ MỚI GỌI BACKTRACK(A, B, C, D) ĐIỀU NÀY KHÔNG SAI TUY NHIÊN SẼ LÀM ĐIỀU CHỈNH BIẾN A 
            SAU ĐÓ TA LẠI PHẢI GÁN LẠI BIẾN A NGAY TỪ ĐẦU RẤT MẤT THỜI GIAN MÀ CHÚNG TA NÊN 

            BACKBACK(A + 1, B + 2, C, D) ĐIỀU NÀY SẼ GIÚP CHÚNG TA QUẢN LÝ BIẾN TRÊN MỖI NÚT TỐT HƠN VÀ ĐIỀU NÀY CÓ NGHĨA LÀ 

            CHÚNG TA ĐANG Ở NÚT BACKTRACK(A, B, C, D) SAU ĐÓ CHÚNG TA SẼ NGẢY SANG NÚT BACKTRACK(A + 1, B + 2, C, D) 
            TUY NÓ CHỈ LÀ 1 CHI TIẾT NHỎ NHƯNG NÓ CŨNG TẠO NÊN SỰ KHÁC BIỆT GIÚP CODE CỦA CHÚNG TA CLEAN VÀ RẤT ĐẸP  

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ITEM_MAX    10000
#define INF         10000

int numItem, weightBag, money = -INF; 
struct Item
{
    int weight = 1; 
    int value = 0; 
    bool operator< (const Item &other) const {
        return (value * other.weight) > (other.value * weight); 
    }
}; 
Item items[ITEM_MAX]; 

void init()
{
    cin >> numItem; 
    cin >> weightBag; 
    for (int i = 1; i <= numItem; i++) cin >> items[i].weight >> items[i].value;
    sort(items + 1, items + numItem + 1); 
}

void backtrack(int pos, int weightCur, int moneyCur, int &money) 
{
    for (int i = pos; i <= numItem; i++) {

        if (weightCur + items[i].weight <= weightBag) {

            // UPPER_BOUND = VI TRI DEN HIEN TAI + VI TRI TU HIEN TAI DEN I + VI TRI TOT NHAT TU I DEN HET 
            int max_money = moneyCur + items[i].value + (weightBag - weightCur - items[i].weight) * items[i + 1].value / items[i + 1].weight;

            if (max_money > money) {
                backtrack(i + 1, weightCur + items[i].weight, moneyCur + items[i].value, money); 

                // CHỖ NÀY LÀ QUAY LUI LẠI NÚT 

                // CHÚNG TA CÓ THỂ HIỂU ĐƠN GIẢN LÀ ĐỆ QUY THÌ ĐI TỪ NÚT CHA XUỐNG NÚT CON 
                // CÒN QUAY LUI LÀ CHÚNG TA LÀM NGƯỢC LẠI CHÚNG TA ĐI TỪ NÚT CON VỀ NÚT CHA VÀ CẬP NHẬT LẠI THÔNG TIN TRONG NÚT CHA 

                // KHI CHÚNG TA TRUYỀN & NHƯ THẾ KIA LÀ CHÚNG TA ĐANG THAY ĐỔI TRỰC TIẾP GÍA TRỊ CỦA BIẾN MONEY ĐIỀU NÀY 
                // GIÚP KHI QUAY LUI THÌ CHÚNG TA CẬP NHẬT LẠI GIÚP LẦN ĐỆ QUY TIẾP THEO CHÚNG TA SẼ KHÔNG PHẢI NHẢY VÀO NHÁNH KHÔNG 
                // CẦN THIẾT NỮA 
                money = max(money, moneyCur + items[i].value); 
            }
        }
    }
}

void process()
{
    int moneyCur = 0, weightCur = 0; 

    for (int i = 1; i <= numItem; i++) {
        if (items[i].weight <= weightBag) {
            int max_money = moneyCur + items[i].value + (weightBag - weightCur - items[i].weight) * items[i + 1].value / items[i + 1].weight;

            if (max_money > money) {
               backtrack(i + 1, weightCur + items[i].weight, moneyCur + items[i].value, money); 
               money = max(money, moneyCur + items[i].value); 
            }
        }
    }

    cout << money << endl; 
}

int main()
{
    init(); 
    process(); 
    return 0; 
}