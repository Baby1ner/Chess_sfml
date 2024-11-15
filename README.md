# Шахматы, написанные на с ипользованием библиотеке SFML
  В данном проекте представлена реализация классической игры в шахматы, в которой два игрока могут соревноваться друг с другом на одном устройстве, управляя фигурами на шахматной доске.
  ![Game_look](https://github.com/Baby1ner/Chess_sfml/tree/master/images/Chess_sfml_KOolKBQMez.png)
## Подробнее об игре
  Шахматы — это стратегическая настольная игра для двух игроков, которая играется на квадратной доске размером 8x8 клеток. Игроки поочередно делают ходы своими фигурами, пытаясь поставить короля противника в шах и мат, т.е. в такую ситуацию, когда король не может избежать взятия.
### Фигуры
<dl>
  <li>Король — Самая важная фигура на доске. Он может двигаться на одну клетку в любом направлении. Когда его съедают, игра заканчивается.</li>
  <li>Ферзь — самая сильная фигура на доске. Он может двигаться на любое количество клеток по вертикали, горизонтали или диагонали.</li>
  <li>Ладья — двигается по вертикали и горизонтали на любое количество клеток.</li>
  <li>Конь — двигается буквой "Г", т.е. на две клетки в одном направлении и на одну клетку в перпендикулярном. Конь — единственная фигура, которая может перескакивать через другие фигуры.</li>
  <li>Слон — двигается по диагонали на любое количество клеток.</li>
  <li>Пешка — двигается на одну клетку вперед, но при первом ходе может двигаться на две клетки. Пешка бьет по диагонали на одну клетку вперед. Когда пешка достигает последней линии противника, она превращается в ферзя.</li>
</dl>
### Цель игры
Цель игры — съесть короля противника.
### Основные правила
<dl>
<li>Игроки делают ходы по очереди.</li>
<li>Фигуры могут перемещаться только в пределах доски.</li>
</dl>

