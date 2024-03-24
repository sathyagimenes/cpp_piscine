_Classes_
Definição: Uma classe em C++ é um modelo ou um protótipo que define atributos (dados) e métodos (funções) que caracterizam um determinado tipo de objeto.

Características: Uma classe define o que um objeto será, mas não é o objeto em si. Ela pode ter variáveis membro (também conhecidas como propriedades ou campos) e funções membro (métodos).

_Instancias_
Definição: Uma instância de uma classe (também conhecida como objeto) é uma realização concreta da classe. Quando você cria um objeto de uma classe, você está criando uma instância dessa classe.

Criação de Instâncias: As instâncias são criadas usando o construtor da classe. Em C++, isso geralmente é feito usando o operador new para alocação dinâmica ou diretamente sem ele para alocação estática.

Uma classe é como um blueprint que define a estrutura e o comportamento (através de métodos) dos objetos, enquanto uma instância é um objeto real criado com base nesse blueprint. As instâncias de uma classe possuem os atributos definidos pela classe, e você pode interagir com esses atributos através dos métodos da classe. Cada instância tem seu próprio conjunto de dados, então mudar um atributo em uma instância não afeta outras instâncias da mesma classe.

_Operador new_
Alocação de Memória: O new é usado para alocar memória no heap para um objeto ou uma matriz de objetos. Inicialização: Ao alocar um objeto, o new invoca o construtor da classe para inicializar o objeto. Ele retorna um ponteiro para o objeto alocado.

Quando usar o new: O new deve ser usado quando deseja-se que o objeto permaneça existindo até que você exclua(delete) ele. Esse objeto poderá ser usado fora do escopo de onde a classe foi declarada. Se você não utilizar o operador new, o objeto será destruido automaticamente quando sair do escopo.

_Operador delete_
Desalocação de Memória: O delete é usado para liberar a memória que foi alocada previamente pelo new. Chamada do Destrutor: Ao desalocar um objeto, o delete invoca o destrutor da classe para limpar recursos. Uso: A sintaxe básica é delete variavel; para um único objeto ou delete[] variavel; para um array. Prevenção de Vazamentos de Memória: É crucial usar delete para evitar vazamentos de memória, que ocorrem quando a memória alocada não é liberada.


*Referência*
Em C++, uma referência é uma espécie de alias, ou seja, um outro nome para uma variável já existente. As referências oferecem uma maneira de acessar objetos sem criar uma cópia deles.
Uma vez inicializada, usar o nome da referência é como usar o objeto original. Qualquer alteração feita através da referência afeta diretamente o objeto original.
Ao contrário dos ponteiros, as referências não precisam ser desreferenciadas para acessar o valor do objeto ao qual se referem. Referências não podem ser nulas, enquanto ponteiros podem ser. Ponteiros podem ser realocados para apontar para diferentes objetos, mas referências, uma vez inicializadas, não podem ser feitas para referenciar outro objeto.

ex03:
In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why?
No human A é interessanete usar weapon como referencia, pois a variavel weapon não pode ser alterada para referenciar à outro endereço de memoria. Então necessariamente ao instanciar o human A vamos receber uma referencia à weapon e atribui-la à variavel. Uma vez setado, não pode referenciar outra variavel.
No human B, em sua instancia não recebemos a weapon. teremos um metodo para atribuir valor à esse ponteiro após sua instancia.e essa referencia poderá ser alterada