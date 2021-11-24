## search trees
### 0_0
Дано бинарное поисковое дерево, в котором ключи вершин являются целыми числами в диапазоне от −231 до 231 − 1 включительно. Найдите сумму ключей всех вершин дерева.

Формат входных данных
Входной файл содержит последовательность чисел — ключи вершин в порядке добавления в дерево. Ключи задаются в формате по одному в строке.
В поисковом дереве все ключи по определению уникальны, поэтому при попытке добавить в дерево ключ, который там уже есть, он игнорируется.

Формат выходных данных
Выведите единственное число — сумму ключей в построенном дереве.
### 0_1
По набору ключей постройте бинарное поисковое дерево и выполните его прямой левый обход.

Формат входных данных
Входной файл содержит последовательность чисел — ключи вершин в порядке добавления в дерево. Ключи задаются в формате по одному в строке.
В поисковом дереве все ключи по определению уникальны, поэтому при попытке добавить в дерево ключ, который там уже есть, он игнорируется.

Формат выходных данных
Выходной файл должен содержать последовательность ключей вершин, полученную прямым левым обходом дерева.
### 0_2
По набору ключей постройте бинарное поисковое дерево. Удалите из него ключ (правым удалением), если он есть в дереве. Выполните прямой левый обход полученного дерева.

Формат входных данных
В первой строке записано целое число — ключ, который нужно удалить из дерева.
Вторая строка пустая.

Последующие строки содержат последовательность чисел — ключи вершин в порядке добавления в дерево. Ключи задаются в формате по одному в строке. Дерево содержит хотя бы две вершины.

Напомним, что в поисковом дереве все ключи по определению уникальны, поэтому при попытке добавить в дерево ключ, который там уже есть, он игнорируется.
Формат выходных данных
Выведите последовательность ключей вершин, полученную прямым левым обходом дерева.
### 0_3
Задано бинарное дерево. Необходимо проверить, является ли оно поисковым.Будем предполагать, что в бинарном поисковом дереве могут быть вершины с одинаковыми ключами. Тогда, для того, чтобы дерево было поисковым, должно выполняться следующее требование: для каждой вершины $x$ все ключи в левом поддереве вершины $x$ меньше ключа вершины $x$, а все ключи в правом поддереве больше либо равны ключу вершины $x$.Формат входных данныхПервая строка входного файла содержит единственное целое число $n$ ($1 \leq n \leq 8 \cdot 10^5$) – количество вершин в дереве.Следующая строка содержит одно целое число $m$ ($-2^{31} \leq m \leq 2^{31} - 1$) – значение в корневой вершине дерева.В каждой из последующих $n - 1$ строк через пробелы перечисляются три параметра $m$, $p$ и $c$, которые задают какую-либо вершину дерева.$m$ – целое число ($-2^{31} \leq m \leq 2^{31} - 1$), значение, записанное в вершине.$p$ – целое число ($1 \leq p \leq n - 1$), номер строки входного файла, в которой был задан родитель текущей вершины (нумерация строк с нуля). Гарантируется, что $p$ меньше, чем номер текущей строки.$c$ может принимать одно из двух значений `L' или `R'. Значение `L' указывает на то, что текущая вершина присоединена к родительской слева, `R' – справа.Гарантируется, что совокупность всех строк задает корректное бинарное дерево.Формат выходных данныхВ единственной строке выведите `YES', если заданное дерево является бинарным деревом поиска, и `NO' в противном случае.
### 0_4
Найти максимальную по значению вершину, расстояние от которой до любой другой вершины дерева строго меньше k и через которую не проходят полупути длины k с висячими концевыми вершинами (длина полупути и расстояние между двумя вершинами измеряется в дугах). Если такая вершина есть, то удалить её правым удалением.
Формат входных данных
В первой строке находится целое число k (0 ≤ k ≤ 109). В последующих строках, в каждой по одному числу — ключи вершин исходного дерева, в порядке добавления в дерево (значения в пределах от 0 до 231 − 1). Число вершин не превосходит 1000.
Формат выходных данных
Выходной файл должен содержать последовательность ключей вершин, полученную прямым левым обходом итогового дерева. Если в результате дерево удалилось полностью, то необходимо вывести в выходной файл сообщение Empty.
## Recursive relations
### MultiMatrix
Дана последовательность из s матриц A1, A2, …, As. Требуется определить, в каком порядке их следует перемножать, чтобы число атомарных операций умножения было минимальным. Матрицы предполагаются совместимыми по отношению к матричному умножению (т. е. число столбцов матрицы Ai − 1 совпадает с числом строк матрицы Ai).

Будем считать, что произведение матриц — операция, которая принимает на вход две матрицы размера k × m и m × n и возвращает матрицу размера k × n, затратив на это kmn атомарных операций умножения. (Базовый тип позволяет хранить любой элемент итоговой и любой возможной промежуточной матрицы, поэтому умножение двух элементов требует одной атомарной операции.)

Так как перемножение матриц ассоциативно, итоговая матрица не зависит от порядка выполнения операций умножения. Другими словами, нет разницы, в каком порядке расставляются скобки между множителями, результат будет один и тот же.

Формат входных данных
В первой строке задано число s матриц (2 ≤ s ≤ 100). В последующих s строках заданы размеры матриц: строка i + 1 содержит через пробел число ni строк и число mi столбцов матрицы Ai (1 ≤ ni, mi ≤ 100). Гарантируется, что mi совпадает с ni + 1 для всех индексов i от 1 до s − 1.
Формат выходных данных
Выведите минимальное число атомарных операций умножения, необходимое для перемножения s матриц.
### 0_2_5
Дано число $N$. Необходимо определить, сколько есть бинарных строк длины $N$, в которых ровно $K$ единиц.Формат входных данныхПервая строка входного файла содержит два целых неотрицательных числа $N$ и $K (0 \le K \le N \le 1000000)$.Формат выходных данныхВыведите одно число - ответ на задачу. Так как ответ может быть очень большим, необходимо его вывести по модулю $10^9 + 7$.
### palindrom
Вводится непустая строка S, которая имеет длину не более 7000 символов и состоит только из строчных латинских букв. Необходимо удалить из строки минимальное число символов так, чтобы получился палиндром (строка символов, которая читается слева направо и справа налево одинаково).

Формат входных данных
В первой строке записана исходная строка S.
Формат выходных данных
Выведите в первой строке длину получившегося палиндрома, а во второй строке сам палиндром (если палиндромов несколько, то выведите только один из них).
### 69.Kuvsh
В одном очень длинном и узком пруду по кувшинкам прыгает лягушка. Кувшинки в пруду расположены в один ряд. Лягушка начинает прыгать с первой кувшинки ряда и хочет закончить на последней. Но в силу вредности характера лягушка согласна прыгать только вперед через одну или через две кувшинки. Например, с кувшинки номер 1 она может прыгнуть лишь на кувшинки номер 3 и номер 4.

На некоторых кувшинках сидят комарики. А именно, на i-й кувшинке сидят ai комаров. Когда лягушка приземляется на кувшинку, она съедает всех комариков, сидящих на ней. Лягушка хочет спланировать свой маршрут так, чтобы съесть как можно больше комаров. Помогите ей: подскажите, какое максимальное число комаров она может съесть за своё путешествие.

Формат входных данных
Первая строка входа содержит число n кувшинок в пруду (1 ≤ n ≤ 1000). Вторая строка содержит n чисел, разделённых одиночными пробелами: i-е число сообщает, сколько комаров сидит на i-й кувшинке. Все числа целые, неотрицательные и не превосходят 1000.
Формат выходных данных
Выведите максимальное число комаров, которое может съесть лягушка. Если лягушка не может добраться до последней кувшинки, то выведите −1.
### Probirki
Заданы три пробирки по 100 литров каждая. Две пробирки могут иметь деления, причём деления у первой и второй пробирки совпадают. Третья пробирка делений не имеет. Деления — это отметки, i-я из которых обозначает число di литров.

Имеется 100 литров воды, которая разлита в три пробирки. Известно, какой объём воды находится в каждой из двух пробирок с делениями в начальный момент времени, оставшаяся жидкость находится в третьей пробирке. Необходимо определить, можно ли отмерить в третью пробирку ровно x литров воды. Если можно, то за какое минимальное число переливаний. Разрешается выливание (в другую пробирку) из пробирки до метки или доливание (из другой пробирки) в пробирку до метки. Разрешается также выливать (в другую пробирку) всю воду из пробирки.

Формат входных данных
Первая строка содержит целое число x литров воды, которое надо отмерить в третью пробирку (0 ≤ x ≤ 100). Вторая и третья строки содержат целые числа k и l литров воды в первой и второй пробирках в начальный момент времени (0 ≤ k + l ≤ 100). Четвёртая строка содержит деления пробирок — целые числа di (1 ≤ di ≤ 99), записанные через пробел в порядке возрастания. Строка завершается нулём.
Формат выходных данных
Выведите минимальное число переливаний. Если отмерить x литров воды в третью пробирку нельзя — то сообщение No solution.
## Data structures
### BinSearch
Необходимо реализовать бинарный поиск на отсортированном в неубывающем порядке массиве чисел.Использование готовых функций бинарного поиска из стандартных библиотек запрещается.Формат входных данныхВ первой строке записано число $n$ ($0 < n \le 3 \cdot 10^5$) — длина массива чисел. Во второй строке записано $n$ чисел через пробел.В третьей строке записано число $k$ ($0 < k \le 3 \cdot 10^5$) запросов. В четвертой строке записано $k$ чисел-запросов, разделённых пробелом.Формат выходных данныхДля каждого числа-запроса $x$ в отдельной строке выведите через пробел числа $b$, $l$ и $r$, где $b$ равно $1$, если $x$ присутствует в массиве, и $0$ в противном случае, $l$ — индекс первого элемента, большего либо равного $x$, $r$ — индекс первого элемента, большего $x$.
### IsbinnaryHeap
Напомним, что для компактного хранения в памяти компьютера полного бинарного дерева на n вершинах можно использовать одномерный массив длины n. Ключи вершин являются значениями элементов массива, индексация начинается с единицы, при этом у элемента с индексом i сыновьями являются элементы с индексами 2i и 2i + 1 (если такие элементы существуют).

Бинарная куча — полное бинарное дерево, для которого выполняется основное свойство структуры данных «куча»: элементы организованы таким образом, что приоритет любой вершины не ниже приоритета каждого из её сыновей.

Будем предполагать, что среди элементов тот элемент имеет наибольший приоритет, у которого ключевое значение меньше (Min-Heap).

Задан массив из n чисел. Необходимо проверить, может ли он представлять бинарную кучу.

Формат входных данных
В первой строке записано число n элементов в массиве (1 ≤ n ≤ 100 000). Во второй строке через пробел записаны n целых чисел, не превосходящих по модулю 109, — элементы массива.
Формат выходных данных
Выведите Yes, если существует бинарная куча, которая в памяти представляется заданным массивом, или No иначе.
### Binominal_Heap
Биномиальное дерево высоты k обозначается через Bk и определяется следующим образом.

Биномиальное дерево B0 состоит из одной единственной вершины.
Биномиальное дерево Bk образуется присоединением биномиального дерева высоты k − 1 к корню другого биномиального дерева высоты k − 1 (во время присоединения корень одного из деревьев полагается одним из сыновей корня другого дерева).
Таким образом, биномиальное дерево Bk имеет корневую вершину, сыновьями которой являются корни биномиальных деревьев B0, B1, B2, …, Bk − 1.
Биномиальная куча состоит из набора биномиальных деревьев попарно различной высоты. Другими словами, для любого k ≥ 0 биномиальное дерево Bk либо не входит в состав кучи, либо входит ровно один раз.

Дано общее число n вершин в биномиальной куче. Определите, из каких биномиальных деревьев может состоять эта куча.

Формат входных данных
На входе задано одно число n вершин в куче (1 ≤ n ≤ 1018).
Формат выходных данных
Для каждого биномиального дерева Bk в составе кучи выведите в отдельной строке одно целое число — высоту k. Деревья следует вывести по возрастанию высоты. Все деревья должны иметь различные порядки, а сумма порядков должна быть n.
Если решений несколько, выведите любое. Если решений нет и биномиальную кучу с заданным числом вершин построить нельзя, выведите −1.
### Chess
Имеется шахматная доска n × m клеток (верхний левый квадрат доски имеет координаты (1, 1), правый нижний — (n, m)). Некоторые поля на ней заняты белыми и чёрными фигурами (ладья, слон, конь, король и ферзь) и пешками. Каждое поле, занятое белыми фигурами и белыми пешками, определяется отрицательным числом −1, а чёрными фигурами и чёрными пешками — числом 1.

Необходимо определить маршрут белого коня из поля (x1, y1) в поле (x2, y2), при котором число его ходов минимально. Взятие белым конём чёрной фигуры или пешки считается дополнительным ходом (т. е. ход на поле, занятое чёрной фигурой или чёрной пешкой, стоит два хода).

Формат входных данных
В первой строке задаются размеры поля n и m (1 ≤ n, m ≤ 1000).
Следующие n строк задают поле (по m чисел в строке).

В последней строке заданы числа x1, y1, x2 и y2.

Формат выходных данных
В единственной строке выведите минимальное число ходов или сообщение No, если пути не существует.
## graphs_algorythms
### 0-1
Берляндия состоит из $n$ городов. Изначально все города изолированы (между городами нету дорог). По очереди будут добавляться дороги между парами городов. Необходимо после каждой добавленной дороги узнать, какое количество компонент связности из городов получилось.Формат входных данныхПервая строка входного файла содержит два числа $n$ и $q$ $(1 \le n, q \le 500000)$ - количество городов и запросов соответственно.Каждая из следующих $q$ строк состоит из двух чисел $u, v$ - между какой парой городов будет построена дорога. Гарантируется, что между любой парой городов строится не более одной дороги и для любого запроса $u \ne v$.Формат выходных данныхНа каждый запрос второго типа необходимо вывести одно число - количество компонент связности в графе из городов.
### 0-2
В Берляндии $n$ городов, связанных $m$ дорогами. Гарантируется, что изначально граф из городов связный, т.е. существует путь между любой парой вершин.В Берляндии происходит $q$ землетрясений, в ходе каждого из них разрушается ровно одна дорога. Необходимо после каждого землетрясения узнать, является ли полученный граф из городов связным. После очередного землетрясений дорога не перестраивается, то есть разрушается навсегда.Формат входных данныхПервая строка входного файла содержит три числа $n$, $m$, $q$ $(1 \le n, m, q \le 100000)$ - количество городов, дорог и землетрясений в Берляндии соответственно.Следующие $m$ строк содержат по два натуральных числа $u$ и $v$ $(1 \le u, v \le n)$ - номера городов, связанных дорогой. Гарантируется, что $u \ne v$ и между каждой парой городов существует не больше одной дороги.Следующие $q$ строк содержат по одному числу $x_i$ $(1 \le x_i \le m)$ - номер дороги, которая пострадает во время $i$-ого землетрясения. Гарантируется, что два различных землетрясения не разрушают одну и ту же дорогу.Формат выходных данныхВыведите строку длины $q$ из нулей и единиц. $i$-ый символ равен 1, если после $i$-ого землетрясения граф оказался связным, в противном случае выведите 0.
### 0-4
Неориентированный граф задан списком рёбер. Постройте матрицу смежности этого графа. Гарантируется, что в графе нет петель и кратных рёбер.

Формат входных данных
В первой строке записаны два целых числа n и m — число вершин (1 ≤ n ≤ 100) и число рёбер графа (0 ≤ m ≤ n(n − 1) / 2). Вершины графа пронумерованы числами от 1 до n. В следующих m строках описаны рёбра: в каждой строке заданы через пробел две вершины u и v (1 ≤ u, v ≤ n, причём u и v различны), которые соединены ребром.
Формат выходных данных
Выведите матрицу смежности графа: n строк по n чисел, каждое число — 0 или 1, числа в строках разделены пробелами.
### 0-5
Задан ориентированный граф, который является корневым деревом. Вершины графа пронумерованы целыми числами от 1 до n. Дуги направлены от корня к листьям. Выведите канонический способ задания этого дерева.

Каноническим способом представления корневого дерева на n вершинах называется массив P размера n, где pi — отец вершины i, а если вершина i является корнем дерева, то pi полагается равным нулю.

Формат входных данных
В первой строке записано целое число n (1 ≤ n ≤ 100 000). В последующих n − 1 строках заданы дуги графа. Дуга, идущая из вершины u в вершину v, задаётся парой чисел u и v, записанных через пробел (1 ≤ u, v ≤ n). Гарантируется, что граф представляет собой корневое дерево.
Формат выходных данных
Выведите n чисел — элементы массива P.
### 0-6
Неориентированный граф задан списком рёбер. Постройте список смежности этого графа. Гарантируется, что в графе нет петель и кратных рёбер.

Формат входных данных
В первой строке записаны два целых числа n и m — число вершин (1 ≤ n ≤ 100 000) и число рёбер графа (0 ≤ m ≤ 200 000). Вершины графа пронумерованы числами от 1 до n. В следующих m строках описаны рёбра: в каждой строке заданы через пробел две вершины u и v (1 ≤ u, v ≤ n, причём u ≠ v), которые соединены ребром.
Формат выходных данных
Выведите список смежности графа в виде n строк. В i-й строке выведите число вершин, смежных с i-й вершиной, а затем номера этих вершин через пробел в произвольном порядке.
### 0-7
Задан ориентированный граф, который является корневым деревом. Вершины графа пронумерованы целыми числами от 1 до n. Дуги направлены от корня к листьям. Выведите канонический способ задания этого дерева.

Каноническим способом представления корневого дерева на n вершинах называется массив P размера n, где pi — отец вершины i, а если вершина i является корнем дерева, то pi полагается равным нулю.

Формат входных данных
В первой строке записано целое число n (1 ≤ n ≤ 100). В последующих n строках задана матрица смежности графа. Если в графе есть дуга, ведущая из вершины i в вершину j, то в i-й строке матрицы j-е число равно 1, иначе 0. Числа разделяются одиночными пробелами. Гарантируется, что граф на входе представляет собой корневое дерево.
Формат выходных данных
Выведите n чисел — элементы массива P.
### 0-8
Для ориентированного графа, заданного матрицей смежности, выполнили поиск в ширину. При неоднозначности выбора очередной вершины всегда выбирали вершину с меньшим номером. В процессе поиска в ширину в момент посещения вершины ей присваивали метку (нумерация меток начинается с единицы). Определите, какую метку получила каждая из вершин графа (поиск в ширину выполняли до тех пор, пока все вершины не получили метки).

Формат входных данных
В первой строке записано целое число n вершин орграфа (1 ≤ n ≤ 100). Вершины нумеруются числами от 1 до n. Далее записана матрица смежности графа: n строк по n чисел, каждое из которых — 0 или 1. Числа разделяются одиночными пробелами. Гарантируется, что все элементы на главной диагонали нулевые.
Формат выходных данных
Выведите n чисел, i-е из которых — метка, которую получила вершина i.
### 0-9
Для ориентированного графа, заданного матрицей смежности, выполнили поиск в глубину. При неоднозначности выбора очередной вершины всегда выбирали вершину с меньшим номером. В процессе поиска в глубину в момент посещения вершины ей присваивали метку (нумерация меток начинается с единицы). Определите, какую метку получила каждая из вершин графа.

Формат входных данных
В первой строке записано целое число n вершин орграфа (1 ≤ n ≤ 100). Вершины нумеруются числами от 1 до n. Далее записана матрица смежности графа: n строк по n чисел, каждое из которых — 0 или 1. Числа разделяются одиночными пробелами. Гарантируется, что все элементы на главной диагонали нулевые.
Формат выходных данных
Выведите n чисел, i-е из которых — метка, которую получила вершина i.
### 0-10
Задан неориентированный взвешенный псевдограф, вершины которого — числа от 1 до n. Требуется найти кратчайшую цепь между вершинами 1 и n. Гарантируется, что (1, n)-цепь существует.

Формат входных данных
В первой строке содержатся целые числа n и m (1 ≤ n ≤ 200 000, 0 ≤ m ≤ 300 000), где n — число вершин, а m — число рёбер в псевдографе. Далее в m строках содержатся сами рёбра, по одному в строке. Каждое ребро задается тремя числами ui, vi, wi (1 ≤ ui, vi ≤ n, 0 ≤ wi ≤ 11111), где ui, vi — это концы ребра, а wi — его длина.
Формат выходных данных
Выведите одно число — длину кратчайшей цепи.
### Ulicnaia-gonka
План улицы для гонки задан в виде точек, помеченных числами от 0 (старт) до N − 1 (финиш), и стрелок, которые их соединяют. Стрелками представлены улицы с односторонним движением. Участники гонки передвигаются от точки к точке по улицам в направлении стрелок. В каждой точке участник может выбрать любую из исходящих стрелок.

Назовём план улицы хорошим, если он обладает следующими свойствами:

каждая точка плана может быть достигнута со старта;
финиш может быть достигнут из любой точки плана;
у финиша нет исходящих стрелок.
Для достижения финиша участник не обязательно должен пройти через все точки. Однако некоторые точки невозможно обойти. Назовём их неизбежными.

Предположим, что гонка проводится на протяжении двух последовательных дней. Для этой цели план должен быть разбит на два «хороших» плана, по одному на каждый день. В первый день стартом является точка 0, а финишем служит некоторая «точка разбиения». Во второй день старт находится в этой «точке разбиения», а финиш — в точке N.

Точка S является «точкой разбиения» для «хорошего» плана C, если:

S отличается от старта и финиша плана C;
план разбивается ею на два «хороших» плана без общих стрелок (т. е. между планами нет стрелок, их соединяющих) и с единственной общей точкой S.
Для заданного «хорошего» плана необходимо:

[1)]
определить множество «неизбежных точек», которые должны посетить все участники гонки (за исключением старта и финиша);
определить множество всех возможных «точек разбиения».
Формат входных данных
В первой строке задано число N точек (0 ≤ N ≤ 50).
Следующие N строк содержат конечные точки стрелок, исходящих соответственно из точек с номерами от 0 до N − 1. Каждая из этих строк заканчивается числом −2.

Формат выходных данных
В первой строке выведите число «неизбежных точек» в заданном плане, затем — их номера в порядке возрастания.
Во второй строке — число «точек разбиения» в заданном плане, затем — их номера в порядке возрастания.

Если каких-либо точек нет, то соответствующая строка должна содержать число 0.
## control test-1
Задана матрица A натуральных чисел из n строк и m столбцов. За каждый проход через клетку с индексами (i, j) взимается штраф Ai, j. Необходимо с минимальным штрафом пройти из какой-либо клетки 1-й строки в n-ю строку, при этом из текущей клетки (i, j) можно перейти в любую из трёх соседних, стоящих в строке с номером, на единицу большим: (i + 1, j − 1), (i + 1, j), (i + 1, j + 1) (если они существуют).

Формат входных данных
Первая строка содержит размеры матрицы n и m (2 ≤ n ≤ 200, 1 ≤ m ≤ 1000). Следующие n строк содержат элементы матрицы A штрафов по строкам, в строке числа разделяются пробелами (все числа натуральные и не превосходят 1 000 000).
Формат выходных данных
Выведите одно число — минимальный штраф.
