/*
Guia0103 - v0.3. - 09 / 03 / 2021
Author: 724577 - Leo Soares
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0103 ./Guia0103.cpp
No Windows: g++ -o Guia0103.exe Guia0103.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0103
No Windows: Guia0103
*/
// lista de dependencias
#include "karel.hpp" //(necessario estar na mesma pasta)
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar um marcador no mundo
world->set ( 4, 4, BEEPER );
// salvar a configuracao atual do mundo
world->save( fileName );
} // decorateWorld ( )
/**
Classe para definir robo particular (MyRobot),
a partir do modelo generico (Robot)
Nota: Todas as definicoes irao valer para qualquer outro robo
criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
public:
/**
turnRight - Procedimento para virar 'a direita.
*/
void turnRight ( )
{
// testar se o robo esta' ativo
if ( checkStatus ( ) )
{
// o agente que executar esse metodo
// devera' virar tres vezes 'a esquerda
turnLeft ( );
turnLeft ( );
turnLeft ( );
} // end if
} // end turnRight ( )
/**
doPartialTask - Metodo para especificar parte de uma tarefa.
*/
void doPartialTask( )
{
	move( );
	move( );
	move( );
	turnLeft ( );
}  //end doPartialTask( )
/**
doTask - Relacao de acoes para o robo executar
*/
void doTask ( )
{
	doPartialTask( );
	doPartialTask( );
	doPartialTask( );
	doPartialTask( );
	turnLeft( );
	turnOff( ); //encerrar
} //end doTask( );
}; // end class MyRobot
// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
world->create ( "" ); // criar o mundo
decorateWorld ( "Guia0103.txt" );
world->show ( );
// preparar o ambiente para uso
world->reset ( ); // limpar configuracoes
world->read ( "Guia0103.txt" );// ler configuracao atual para o ambiente
world->show ( ); // mostrar a configuracao atual
set_Speed ( 3 ); // definir velocidade padrao
// criar robo
MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
robot->doTask ( );
// encerrar operacoes no ambiente
world->close ( );
// encerrar programa
getchar ( );
return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( ) identificacao de programa
*/