#include<iostream> 
#include <iomanip> // BIBLIOTECA PARA APROXIMAR A SAIDA DAS PORCENTAGENS
#include<windows.h> // BIBLIOTECA PARA COLOCAR A COR 
using namespace std;

int som(){
	Beep(3000, 500);
	Beep(3000, 500);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 50);
	Beep(2000, 50);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 50);
	Beep(2000, 50);
	Beep(3000, 70);
	Beep(2000, 70);
	Beep(3000, 50);
	Beep(2000, 50);
	
}

int main(){
	
	system("color 70"); // PRIMEIRO ALGARISMO = COR DE FUNDO; SEGUNDO = COR DA LETRA 
	setlocale(LC_ALL, "portuguese");
	
	int voto, contador = 0, empate = 0, maior_voto = 0, disciplina_posicao = 0;
	int idades[]={30, 35, 56, 40, 37, 21, 29}, nums[]={1,2,3,4,5,6,7,8};
	double conts_votos[]={0, 0, 0, 0, 0, 0, 0, 0, 0};
	char confirmacao;
	string frase = "A disciplina escolhida é do(a) professor(a)";
	string profs[]={" Thadeu", " Vagner", " Henrique", " Galbinha", " Rodolfo", " Larissa", " Rosa"};
	string disciplinas[]={"Algoritmo", "Matemática", "Física", "Eletricidade", "Filosofia", "Artes", "Português", "BRANCO", "Nulos"};
	string grupo[]={"Carol Santana","Danyella Ketley","Denyse Nascimento", "Karolayne Raquel", "Laura Roscelle"};
	
	do{ 
		cout << "Votação da Disciplina mais Show de Bola do IFRN\n";
		cout << "___________________________________________________\n";
		//APARECE TABELA
		for(int i=0; i<9; i++){ 
			if(i==8){ cout << "Para Encerrar Votação" << "\t0" << endl;}
			else{ cout << "Para " << disciplinas[i] << "      \t" << nums[i] << endl;}
		}
		
		//PERGUNTA QUAL O VOTO 
		cout << "___________________________________________________\n";
		cout << "\tQual o seu voto? "; 
		cin >> voto;	
		
		//MOSTRA O PROFESSOR DA REFERIDA MATÉRIA VOTADA 
		for(int i=0; i<1; i++){ 
			if(voto>= 1 && voto <=7){ 
				cout << frase << profs[voto-1] << "\n";
			}else if(voto == 8){
				cout << "Você votou branco! \n";
			}else if(voto>8 ||voto < 0){
				cout << "Você votou nulo! \n";
			}
		}
		//VERIFICAÇÃO 
		cout << "Você tem certeza de sua escolha??? (s ou n): "; 
		cin >> confirmacao;
		
		while(confirmacao == 'n' || confirmacao == 'N'){
			cout << "Informe seu voto novamente: ";
			cin >> voto;	
			
			//MOSTRA O PROFESSOR DA REFERIDA MATÉRIA VOTADA 
			for(int i=0; i<1; i++){ 
				if(voto>= 1 && voto <=7){ 
					cout << frase << profs[voto-1] << "\n";
				}else if(voto == 8){
					cout << "Você votou branco! \n";
				}else if(voto>8 || voto < 0){
					cout << "Você votou nulo! /n";
				}
				cout << "Você tem certeza de sua escolha ??? (s ou n): ";
				cin >> confirmacao;	
			}
		}
	
		// CONFIRMA E AGRADECE
		if(confirmacao == 's' || confirmacao == 'S'){ 
			cout << "\tSeu voto foi confirmado!\n" << "\t\t OBRIGADO(A)\t\n";
		som();		
		system("pause");
		system("cls");	
		
   			// LAÇO QUE CONTABILIZA OS VOTOS VÁLIDOS
			for(int i=0; i<9; i++){
				if(voto == nums[i]){ conts_votos[i]++; contador ++; }
			} 
			// CONTABILIZA OS VOTOS NULOS E FINALIZA
			if(voto > nums[7] || voto == 0){ 
				conts_votos[8]++; 
				if (voto==0){ cout << "\t\t\tVOTAÇÃO FINALIZADA!\n\n"; }
			}
		} 		
	}while(voto != 0);
	
   	// A PORCENTAGEM DE CADA DISCIPLINA 
	for (int i=0; i<9; i++){
		
		cout << setiosflags (ios::fixed) << setprecision(0); 
		
		if (i > 6){ 
			cout << "Votos " << disciplinas[i] << ": " << conts_votos[i] << endl;
		}else{ 
			cout << "A disciplina de " << disciplinas[i] << " teve:     \t" << conts_votos[i] << " votos - Equivalente a ";
			
			if(conts_votos[i] == 0){ // PORQUE QUANDO É ZERO NA PORCENTAGEM APARECE NAM
				cout << "0% dos votos\n";
			}else{ 
				cout << (conts_votos[i]/contador)*100 << "% dos votos\n";
			}
		}
	}
	//VARRE OS VOTOS ATÉ ENCONTRAR A MAIOR QUANTIDADE DE VOTOS RECEBIDOS EM UMA MESMA MATÉRIA
	for(int i=0; i<9; i++){
		if(maior_voto < conts_votos[i] && i<7){
			maior_voto = conts_votos[i];			
		}
	}
	//VARRE NOVAMENTE PARA CHECAR SE HOUVE EMPATE COM O MAIOR NÚMEROS DE VOTOS
	for(int i=0; i<9; i++){
		if(maior_voto == conts_votos[i] && i<7){
			empate ++;
			//CASO OCORRA USA O CRITÉRIO DA IDADE PARA DESEMPATE E SALVA A RESPECTIVA POSIÇÃO DA MATÉRIA
			if(empate > 1 && idades[i]>=idades[disciplina_posicao] && i<7){
				disciplina_posicao = i;	
			//CASO NÃO OCORRA SALVA A POSIÇÃO DA MATÉRIA COM O MAIOR NÚMERO DE VOTOS 
			}else if(empate < 2 && i<7){
				disciplina_posicao = i;
			}		
		}
	}
	
	cout << "\t\tQuantidade de votos válidos: " << contador << endl;
	//SE NENHUMA MATÉRIA RECEBER VOTOS
	if(maior_voto == 0){
		cout << "RESULTADO FINAL: Nenhuma disciplina foi votada, portanto nenhuma foi eleita a mais show de bola.\n\n";
	//SE HOUVER VOTAÇÃO APARECE O RESULTADO 
	}else{
		cout << "RESULTADO FINAL: A disciplina de " << disciplinas[disciplina_posicao] << " foi eleita como a mais show de bola.\n";
		if(empate > 1){ cout << "Como critério de desempate foi usado a idade.\n\n"; }
	}
	
	system ("pause"); 
	cout << "\n\n ============ Credits by group  ============== \n" << endl; 
	for(int i=0; i<5; i++){ cout << "Name " << grupo[i] << endl; }
}

	
	



