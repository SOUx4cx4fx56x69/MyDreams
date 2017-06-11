#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
//shitcode one love, so it dream(sleap)
/*
<A> жиза
<A> https://github.com/codingPrimate/MyDreams/blob/master/1/main.c
<A> ебала приснилась
<B> о
<B> дарова
<A> дарова
<A> типо блять строку уменьшать с каждым разом
<A> при хэш
<A> но хэш фикс длинны
<A> сон хуйня
<A> но всерогно попробывал
<A> типо с каждым вызовом типо строка все меньше и меньше и меньше и меньше
<A> до фикс длинны
<A> меньше опр длинны не может быть
<A> но чтобы уменьшалось
<A> хз
<A> пойду кофе заварю
<B> а я уже заварил
<A> я ток проснулся
<A> и пока сон не забыл пытался писать
<B> растворимый
<A> уже забыл 
<A> надо было на пхп писать
<A> сразу
<B> я проснулся и сходил еды взял
<A> получше бы выглядил результат
<A> там готовый hash($algo,$string);
<B> СЛЕЗЗ
<B> СЛЕЗЗ тебе не снился?
<A> слезз?
<A> хз
<A> не там даже прикол не в длинне
<A> я уже сон забыл
<A> типо соль там ещё в начале должна у меня быть
<A> обязательно
<A> и единочально она снижается
<A> в длинне
<A> и потом снижается
<A> и на 3-ий вызов
<A> на 4-ый нету смысла
<B> начитался криптографии
<A> типо можно использовать пока не закончиться))
<A> это типо той хуйни с f(x) f(f(x))
<C> хиротень
<A> x1...x100
<A> типо личность подтвердить
<A> типо одностороняя функция
<A> ну типо в одну сторону
<A> (хэш)
<B> иди кофе вари
<A> соль+пароль допустим 1, в компе значение x101
<A> у человека x100 вычисляя он типо x101
<A> комп x102
<A> а человек x100
<B> я кофе выжрал
<A> и типо пока функция пригодна так можно крутить и пароль уже не нужен
<A> типо
<A> хуево объясняю
<B> купил три средних пачки максима кофе
<A> типо такой хуиты токо оно уменьшаеца
<A> B, у меня норм кофе
<A> большие зерна вся хуйня
<A> но в чем в сне неувязка
<A> хэш опр длинны
<A> но во сне не говорилось про хэш
<A> в общем похуй
*/
void block_(char*string,unsigned char*result,unsigned char*result1,unsigned long * counter)
{
 while(*string)
 {
  for(unsigned short i = 8;i--;)
  {
   *result^=(*string^*(string+1) & 0xFF);
   string+=2;
   *counter+=2;
  }
  *result1+=*result;
 }

}

void first(char*string)
{
 unsigned char result __attribute__((aligned(8)));
 unsigned char result1 __attribute__((aligned(8)));
 unsigned long counter_string_size=0;
 block_(string,&result,&result1,&counter_string_size);
 result=(result|result1) & 0xFF;
 *string++=result;
for(counter_string_size;counter_string_size--;)
  *string++=0;
*string='\0';
}

void second(char*string)
{
char hash[SHA512_DIGEST_LENGTH];
SHA512(string, strlen(string) - 1, hash);
for(unsigned short i =0;hash[i];i++)
 *string++=hash[i++];
*string++='\0';
}

void final(unsigned char*string)
{
 first(string);
 second(string);
 char tmp[strlen(string)];
 unsigned short counter=0;
while(*string)
{
 tmp[counter++]=(*string % 16)+'0';
 *string= *string/16;
 *string++;
}
tmp[counter++]='\0';
for(counter;counter--;)
 *string--=tmp[counter];
}

void main(void)
{
unsigned char * buffer = strdup("Test String");
first(buffer);
second(buffer);
final(buffer);
printf("Result: %s\n",buffer);
}
