# Porting the progams to Turbo C/C++
To run the programs in TurboC/C++, replace
- ```int main() ``` with ```void main()```
- ```return 0;``` with ```getch();```
#### Example:
```c
#include<stdio.h>
int main(){
     printf("Hello World!! Happy Coding!!");
     return 0;
}
```
#### Edited to:
```c
#include<stdio.h>
void main(){
     printf("Hello World!! Happy Coding!!");
     getch();
}
```

