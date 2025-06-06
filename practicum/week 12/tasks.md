# Практикум 12: Подготовка за второ контролно

## Задача 1: Контейнери
Да се дефинира абстрактен клас ```Container```, дефиниращ интерфейс на контейнер, съдържащ числа с плаваща запетая (double). Класът да дефинира следните методи:
- ```bool member (double x)```, проверяващ дали дадено число е елемент на структурата
- ```double operator [] (size_t i)```, намиращ i-тия елемент на структурата. Номерацията на елементите зависи от специфичната структура
- ```int count ()```, връща броя на елементите в структурата
- ```void write ()```, извеждащ на конзолата елементите на структурата.

Да се дефинира наследник ```Vector``` на клас ```Container```, реализиращ вектор от числа с плаваща запетая. Размерът и елементите на вектора се задават при конструиране на обекта. Номерацията на елементите е естествена. Печатането на елементите е последователно на едни ред, разделени със запетая и оградени със скоби (например: (1,2,3))

Да се дефинира наследник ```Matrix``` на клас ```Container```, реализиращ квадратна матрица от числа с плаваща запетая. Размерът и елементите на матрицата се задават при конструиране на обекта. Номерацията на елементите на матрицата е следната: Ако големината на матрицата е N, то елементът (aij), 0<=i<N, 0<=j<N има пореден номер i*N+j.

Да се реализира функция ```bool intersection (const Container** arr, size_t n, double x)```, която по масив от указатели към n контейнера проверява дали има такова число x, което да се съдържа във всяка една от структурите.

## Задача 2: Windows Forms 
Windows Forms е UI framework за лесно създаване на приложения за Windows OS. Той
представя лесен начин за създаване на приложения графично и се поддържа от езикци като C#. Приложенията представляват множество от форми (Forms), в които има контроли (Controls).
Да се създаде клас, който представя **Форма**. Формата има размер (широчина и дължина) и име. Всяка форма поддържа колекция от контроли.

Всеки **контрол** има размер и локация във формата. Също така, всеки контрол има функция `setDataDialog();`, която позволява на потребителя да промени контрола по подходящ начин. Всеки контрол може да променя размерите си. Имаме следните контроли:

1. *TextBox* - Контрол, в който се подава текст. `setDataDialog()` променя текста му.
![check](https://i.stack.imgur.com/AhOpr.jpg)
1. *CheckBox* - Контрол, който има текст и състояние (включен или изключен).
    `setDataDialog()` променя дали е включен или изключен по подразбиране. За промяна на текста може да добавите допълнителна функция.
    ![radio](https://images.theengineeringprojects.com/image/main/2017/10/C-CheckBox-9.png)
    
2. *RadioButton* - Контрол, който има няколко опции, но само една е избрана.
    `setDataDialog()` променя избраната опция. Може да добавите допълнителна логика за промяната на опциите. Броят им, веднъж зададен, не се променя.
    ![radio](https://i.stack.imgur.com/EyNQT.png)

Реализирайте хетерогенен контейнер, който съдържа различните контроли, които вашата форма притежава. 
Трябва да имате следните методи:
- метод за добавяне на контрола към контейнера
- метод за променяне на размера на формата, както и на всеки от контролите (може да достъпвате контролите по индекс)
- функция за промяна на локацията на контролите, като те не трябва да излизат извън формата
- метод `change(size_t index);` който променя контрола на подадения индекс. Промяната става чрез извикване на `setDataDialog` функцията на съответния контрол.

