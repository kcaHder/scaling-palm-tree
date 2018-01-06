# include <iostream>
# include <cstring>
using namespace std;

int main(int narg, char ** args, char ** env)
{
	char* chi_sei, b;
	const char* bancomat = "112233";
	int i = 0, j;
	while(env[i]) if(strstr(env[i++], "LOGNAME")) break;
	chi_sei = strstr(env[i-1], "=");
/* le due righe precedenti sono quanto esegue la
funzione getenv("LOGNAME"); se non la si conosce
ce la si può cavare come qui */
	char* nomedilogin;
	cout << "Dimmi il tuo nome di login\n";
	cin >> nomedilogin;
	b = '\b'*(strcmp(chi_sei+1, nomedilogin) != 0);
	cout << "il tuo bancomat è: ";
	for(j=0; j < strlen(bancomat); ++j) cout << bancomat[j] << b;
	cout << ' ' << endl;
	
}

