int isValid(char *ip)
{   int dot=0;
    if(ip[0]=='.') return 0;
    int i;
    for(i=0;ip[i]!='\0';i++){
        if(ip[i]=='.'){
            dot=1;
        }
        if(((int)ip[i]>=48 && (int)ip[i]<=57) || (int)ip[i]==46){
            
        }
        else return 0;
    }
    
    if(dot==0) return 0;
    if(ip[i-1]=='.') return 0;
    
    
   char* part = strtok(ip, "."); 
   int check=0;
   while(part!=NULL){
       if(part[0]=='0' && part[1]!='\0') return 0;
       int num = stoi(part);
       if(num>255 || num<0) return 0;
       part = strtok(NULL,".");
       check++;
   }
    if(check==4) return 1;
    else return 0;
}