#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
struct mbuffer
{ 
    long msg_type; 
    char msg_text[100]; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid;  
    key = ftok("file", 63);  
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.msg_type = 1; 
  
    printf("Write message : "); 
    gets(message.msg_text); 
    msgsnd(msgid, &message, sizeof(message), 0); 
    printf("message send is : %s \n", message.msg_text); 
  
    return 0; 
} 
