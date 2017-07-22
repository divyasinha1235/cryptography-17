#include<stdio.h>
#include<strings.h>
char *encryption(char[]);
char *decryption(char[]);
void main()
{
   int i ;
   int key;
   int choice;
   char *c_text;
   int flag=0;
   char msg[300];
   printf("enter a plain text: ");
   scanf("%[^\n]",msg);
   printf(" \n Your plain text message is :  %s",msg);
  
   do{
   	printf("\n press '1' for encryption \n,  \n press '2' for decryption \n,   \n press '0 for  Exit  \n ");
   	scanf("%d",&choice);
   	switch(choice)
	 {
	 	case 1:
	 		c_text=encryption(msg);
	 		flag=1;
	 		break;
	 	
		case 2:
		    if(flag==1)
			  decryption(c_text);
			else
			   printf("or perform the encryption process\n");
			break;
		
		case 0:
		     break;
		
		
		default:
		    printf("enter a valid choice \n");
			break;
				 	    	
	   }  
    }while(choice!=0);
	   
}


char *encryption(char cipher_text[])
{
	int key,i;
	printf("enter the key for encryption =");
	scanf("%d",&key);
	for(i=0; i<strlen(cipher_text); i++)
	{
		if(cipher_text[i]>='a' && cipher_text[i]<='z')
		{
			cipher_text[i]=cipher_text[i]+key;
			if(cipher_text[i]>'z')
			{
				cipher_text[i]=cipher_text[i]-26;
			}
		}
	}
	printf("your encrypted message  =  %s",cipher_text);
	return cipher_text;
}


char *decryption(char cipher_text[])
{
	int key;
	int i;
	char cipher[300];
	strcpy(cipher,cipher_text);
	printf("\n Decryption process \n");
	for(key=1;key<=26;key++)
	{
		for(i=0;i<strlen(cipher_text);i++)
		{
			if(cipher_text[i]>='a' &&  cipher_text[i]<='z')
			{
				cipher[i]=cipher_text[i]-key;
			     if(cipher_text[i]<'a')
			     {
				       cipher_text[i]=cipher_text[i]+26;
			     }
			}
		}
	printf(" \n Decrypted text is %s",cipher);
   }

}
