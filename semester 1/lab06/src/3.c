int main() {
    int num = 5223;
    char result[4][15];
    char thousands[9][20] = { " one thousand ", " two thousands ", " three thousands ", " four thousands ", " five thousands", " six thousands ", " seven thousands ", " eight thousands ", " nine thousands " };     //тысячи
    char hundreds[9][20] = { " one hundred ", " two hundreds ", " three hundreds ", " four hundreds ", " five hundreds ", " six hundreds ", " seven hundreds ", " eight hundreds ", " nine hundreds " };      //сотни
    char exception[10][20] = { " ten ", " eleven ", " twelve ", " thirteen ", " fourteen ", " fifteen ", " sixteen ", " seventeen ", " eighteen ", " nineteen " };     //исключения(11, 12, ...)
    char decs[9][15] = { " twenty ", " thirty ", " fourty ", " fifty ", " sixty ", " seventy ", " eighty ", " ninety " };       //десятки
    char units[9][15] = { " one ", " two ", " three ", " four ", " five ", " six ", " seven ", " eight ", " nine " };
    //единицы

    for (int i = 0; i < 15; i++) {
        result[0][i] = thousands[num / 1000 - 1][i];
        result[1][i] = hundreds[num % 1000 / 100 - 1][i];
        result[2][i] = decs[num % 100 / 10 - 2][i];
        if (num % 100 >= 10 && num % 100 < 20) {        //рассматриваем случай, если у нас "исключения"
            result[3][i] = exception[num % 100 - 10][i];
        }
        else {
            result[3][i] = units[num % 10 - 1][i];      //а тут случай без исключений
        }
    }
    return 0;
}
