/*7. Напишите программу, которая читает слова по одному за раз, пока не будет введена отдельная буква q. 
После этого программа должна сообщить количество слов, начинающихся с гласных, количество слов, начинающихся с согласных, а также количество слов, 
не попадающих ни в одну из этих категорий. 
Одним из возможных подходов может быть применение isalpha() для различения слов, начинающихся с букв, и остальных, с последующим применением if или 
switch для идентификации тех слов, прошедших проверку isalpha(), которые начинаются с гласных. Пример запуска может выглядеть так: 
Enter words (q to quit): 

The 12 awesome oxen ambled 
quietly across 15 meters of lawn, q 

5 words beginning with vowels 
4 words beginning with consonants 
2 others 
*/
#include <iostream>
bool in(char c, const char *symbols) 
{
  while (*symbols) if (c == *symbols++) return true;
  return false;
}
const char vowels[] = "aeiouAEIOU";
const char consonants[] = "qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM";
void menu(void);
int main(void)
{
    std::string enter;
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    menu();
    std::cin >> enter;
    while(enter != "q")
    {
        if(in(enter[0], vowels))
        count++;
        else if(in(enter[0], consonants))
        count1++;
        else
        count2++;
        std::cin >> enter;
    }
    std::cout << count << " words beginning with vowels" << std::endl;
    std::cout << count1 << " words beginning with consonants" << std::endl;
    std::cout << count2 << " others" << std::endl;
    return 0;
}

void menu(void)
{
    std::cout << "Enter words (q to quit):";
}
