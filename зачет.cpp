// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

// Игрок
struct Player {
    int x, y;
    int hp = 100;
    int max_hp = 100;
    int atk = 10;
    int def = 5;
    int lvl = 1;
    int exp = 0;
    int gold = 50;
    bool has_key = false;
};

// Враг
struct Enemy {
    int x, y;
    string name;
    int hp;
    int atk;
    int exp;
};

// Карта
struct Level {
    int num;
    int w, h;
    vector<string> tiles;
    vector<Enemy> enemies;
    int exit_x, exit_y;
    int chest_x, chest_y;
    bool chest_open = false;
};

// Глобальные переменные
Player pl;
Level cur_lvl;
int cur_level_num = 1;
bool game_running = true;

// Функции
void init_level(int level) {
    cur_lvl.num = level;
    cur_lvl.tiles.clear();
    cur_lvl.enemies.clear();

    // Размеры уровней разные
    if (level == 1) {
        cur_lvl.w = 20;
        cur_lvl.h = 10;
        cur_lvl.tiles = {
            "####################",
            "#..................#",
            "#..###........###..#",
            "#..#...........#...#",
            "#......E............#",
            "#..#...........#...#",
            "#..###........###..#",
            "#..................#",
            "#...............X..#",
            "####################"
        };
        cur_lvl.exit_x = 17;
        cur_lvl.exit_y = 8;
        cur_lvl.chest_x = 3;
        cur_lvl.chest_y = 3;
    } else if (level == 2) {
        cur_lvl.w = 22;
        cur_lvl.h = 12;
        cur_lvl.tiles = {
            "######################",
            "#....................#",
            "#.##..##....##..##...#",
            "#....................#",
            "#..E..............E..#",
            "#....##......##......#",
            "#......##..##........#",
            "#....................#",
            "#..##............##..#",
            "#....................#",
            "#...............X...#",
            "######################"
        };
        cur_lvl.exit_x = 19;
        cur_lvl.exit_y = 10;
        cur_lvl.chest_x = 5;
        cur_lvl.chest_y = 5;
    } else if (level == 3) {
        cur_lvl.w = 24;
        cur_lvl.h = 14;
        cur_lvl.tiles = {
            "########################",
            "#......................#",
            "#.####..####..####.....#",
            "#......................#",
            "#..E...................#",
            "#......####....####....#",
            "#......................#",
            "#....####..####..####..#",
            "#......................#",
            "#..E.................E.#",
            "#......####..####......#",
            "#......................#",
            "#.................X...#",
            "########################"
        };
        cur_lvl.exit_x = 21;
        cur_lvl.exit_y = 12;
        cur_lvl.chest_x = 8;
        cur_lvl.chest_y = 8;
    } else if (level == 4) {
        cur_lvl.w = 26;
        cur_lvl.h = 16;
        cur_lvl.tiles = {
            "##########################",
            "#........................#",
            "#..#####....#####........#",
            "#........................#",
            "#....E...............E...#",
            "#........................#",
            "#..#####....#####....#####",
            "#........................#",
            "#....#####....#####....E.#",
            "#........................#",
            "#..E..................E..#",
            "#........................#",
            "#....#####....#####......#",
            "#........................#",
            "#....................X...#",
            "##########################"
        };
        cur_lvl.exit_x = 23;
        cur_lvl.exit_y = 14;
        cur_lvl.chest_x = 12;
        cur_lvl.chest_y = 10;
    } else if (level == 5) {
        cur_lvl.w = 28;
        cur_lvl.h = 18;
        cur_lvl.tiles = {
            "############################",
            "#..............................#",
            "#..#######....#######.........#",
            "#..............................#",
            "#....E.....................E...#",
            "#..............................#",
            "#..#######....#######....#######",
            "#..............................#",
            "#....#######....#######....E....#",
            "#..............................#",
            "#..E..........................E.#",
            "#..............................#",
            "#....#######....#######........#",
            "#..............................#",
            "#..E........................E..#",
            "#..............................#",
            "#......................X.......#",
            "############################"
        };
        cur_lvl.exit_x = 25;
        cur_lvl.exit_y = 16;
        cur_lvl.chest_x = 15;
        cur_lvl.chest_y = 12;
    } else if (level == 6) {
        cur_lvl.w = 30;
        cur_lvl.h = 20;
        cur_lvl.tiles = {
            "##############################",
            "#....................................#",
            "#..#########..#########.............#",
            "#....................................#",
            "#....E...........................E...#",
            "#....................................#",
            "#..#########..#########..#########..#",
            "#....................................#",
            "#....#########..#########..E.........#",
            "#....................................#",
            "#..E...............................E.#",
            "#....................................#",
            "#....#########..#########............#",
            "#....................................#",
            "#..E.............................E..#",
            "#....................................#",
            "#....#########..#########............#",
            "#....................................#",
            "#..........................X.........#",
            "##############################"
        };
        cur_lvl.exit_x = 27;
        cur_lvl.exit_y = 18;
        cur_lvl.chest_x = 18;
        cur_lvl.chest_y = 15;
    } else if (level == 7) {
        cur_lvl.w = 32;
        cur_lvl.h = 22;
        cur_lvl.tiles = {
            "################################",
            "#........................................#",
            "#..###########..###########.............#",
            "#........................................#",
            "#....E...............................E...#",
            "#........................................#",
            "#..###########..###########..###########.#",
            "#........................................#",
            "#....###########..###########..E.........#",
            "#........................................#",
            "#..E...................................E.#",
            "#........................................#",
            "#....###########..###########............#",
            "#........................................#",
            "#..E...............................E.....#",
            "#........................................#",
            "#....###########..###########............#",
            "#........................................#",
            "#..E...........................E.........#",
            "#........................................#",
            "#............................X..........#",
            "################################"
        };
        cur_lvl.exit_x = 29;
        cur_lvl.exit_y = 20;
        cur_lvl.chest_x = 20;
        cur_lvl.chest_y = 18;
    }

    // Расставляем врагов
    srand(time(NULL));
    int enemy_count = 2 + level;
    for (int i = 0; i < enemy_count; i++) {
        int ex, ey;
        do {
            ex = rand() % (cur_lvl.w - 2) + 1;
            ey = rand() % (cur_lvl.h - 2) + 1;
        } while (cur_lvl.tiles[ey][ex] != '.');

        Enemy e;
        e.x = ex;
        e.y = ey;
        e.name = (level < 3) ? "Goblin" : (level < 5) ? "Orc" : "Troll";
        e.hp = 20 + level * 10;
        e.atk = 5 + level * 2;
        e.exp = 15 + level * 5;
        cur_lvl.enemies.push_back(e);
    }

    // Стартовая позиция игрока
    pl.x = 1;
    pl.y = 1;
}

void draw_screen() {
    system("cls");
    cout << "=== LEVEL " << cur_lvl.num << " ===\n";
    for (int y = 0; y < cur_lvl.h; y++) {
        for (int x = 0; x < cur_lvl.w; x++) {
            if (pl.x == x && pl.y == y) {
                cout << '@';
            } else {
                bool is_enemy = false;
                for (auto& e : cur_lvl.enemies) {
                    if (e.x == x && e.y == y && e.hp > 0) {
                        cout << 'E';
                        is_enemy = true;
                        break;
                    }
                }
                if (!is_enemy) {
                    if (x == cur_lvl.chest_x && y == cur_lvl.chest_y && !cur_lvl.chest_open) {
                        cout << 'C';
                    } else if (x == cur_lvl.exit_x && y == cur_lvl.exit_y) {
                        cout << 'X';
                    } else {
                        cout << cur_lvl.tiles[y][x];
                    }
                }
            }
        }
        cout << '\n';
    }

    cout << "\nHP: " << pl.hp << "/" << pl.max_hp << " | LVL: " << pl.lvl << " | EXP: " << pl.exp << "/" << (pl.lvl * 100) << " | GOLD: " << pl.gold << "\n";
    if (pl.has_key) cout << "Key: YES\n";
    cout << "WASD-move, I-info, Q-quit, U-heal(10 gold)\n";
}

bool can_move(int nx, int ny) {
    if (nx < 0 || nx >= cur_lvl.w || ny < 0 || ny >= cur_lvl.h) return false;
    char tile = cur_lvl.tiles[ny][nx];
    return tile == '.' || tile == 'X' || (nx == cur_lvl.chest_x && ny == cur_lvl.chest_y);
}

void fight(Enemy& e) {
    cout << "\nFIGHT with " << e.name << "!\n";
    while (pl.hp > 0 && e.hp > 0) {
        cout << "Your HP: " << pl.hp << " | Enemy HP: " << e.hp << "\n";
        cout << "1. Attack  2. Heal (potion)\nChoice: ";
        int ch;
        cin >> ch;
        if (ch == 1) {
            int dmg = pl.atk + rand() % 6;
            e.hp -= dmg;
            cout << "You hit for " << dmg << " dmg!\n";
        } else if (ch == 2 && pl.gold >= 10) {
            pl.hp += 30;
            pl.gold -= 10;
            if (pl.hp > pl.max_hp) pl.hp = pl.max_hp;
            cout << "Healed! HP: " << pl.hp << "\n";
        }
        if (e.hp > 0) {
            int edmg = e.atk + rand() % 4 - pl.def / 2;
            if (edmg < 1) edmg = 1;
            pl.hp -= edmg;
            cout << e.name << " hits you for " << edmg << " dmg!\n";
        }
    }
    if (pl.hp > 0) {
        pl.exp += e.exp;
        pl.gold += 10 + cur_lvl.num * 2;
        cout << "You won! +" << e.exp << " exp, +" << (10 + cur_lvl.num * 2) << " gold\n";
        if (pl.exp >= pl.lvl * 100) {
            pl.lvl++;
            pl.max_hp += 20;
            pl.hp = pl.max_hp;
            pl.atk += 3;
            pl.def += 1;
            cout << "LEVEL UP! Now level " << pl.lvl << "!\n";
        }
        e.hp = 0;
    } else {
        cout << "You died...\n";
        game_running = false;
    }
}

void open_chest() {
    if (cur_lvl.chest_open) return;
    cur_lvl.chest_open = true;
    int reward = rand() % 3;
    if (reward == 0) {
        pl.atk += 2;
        cout << "Found a sword! ATK +2\n";
    } else if (reward == 1) {
        pl.def += 2;
        cout << "Found armor! DEF +2\n";
    } else {
        pl.has_key = true;
        cout << "Found a key!\n";
    }
}

void move_player(char dir) {
    int nx = pl.x, ny = pl.y;
    if (dir == 'w') ny--;
    else if (dir == 's') ny++;
    else if (dir == 'a') nx--;
    else if (dir == 'd') nx++;
    else return;

    if (!can_move(nx, ny)) {
        cout << "Cannot move there!\n";
        return;
    }

    for (auto& e : cur_lvl.enemies) {
        if (e.x == nx && e.y == ny && e.hp > 0) {
            fight(e);
            if (!game_running) return;
            break;
        }
    }

    pl.x = nx;
    pl.y = ny;

    if (pl.x == cur_lvl.chest_x && pl.y == cur_lvl.chest_y && !cur_lvl.chest_open) {
        open_chest();
    }

    if (pl.x == cur_lvl.exit_x && pl.y == cur_lvl.exit_y) {
        if (cur_lvl.num == 7) {
            cout << "\n*** YOU WIN! ***\n";
            game_running = false;
        } else {
            cur_level_num++;
            init_level(cur_level_num);
        }
    }
}

void show_info() {
    cout << "\n=== INFO ===\n";
    cout << "Level: " << pl.lvl << "\n";
    cout << "Attack: " << pl.atk << "\n";
    cout << "Defense: " << pl.def << "\n";
    cout << "Gold: " << pl.gold << "\n";
    cout << "Key: " << (pl.has_key ? "YES" : "NO") << "\n";
    cout << "Press Enter...";
    cin.ignore();
    cin.get();
}

int main() {
    srand(time(NULL));
    init_level(1);

    while (game_running) {
        draw_screen();
        char cmd;
        cout << "> ";
        cin >> cmd;
        if (cmd == 'q') break;
        else if (cmd == 'i') show_info();
        else if (cmd == 'u') {
            if (pl.gold >= 10 && pl.hp < pl.max_hp) {
                pl.hp += 30;
                pl.gold -= 10;
                if (pl.hp > pl.max_hp) pl.hp = pl.max_hp;
                cout << "Healed!\n";
            } else {
                cout << "Not enough gold or HP full!\n";
            }
        } else {
            move_player(cmd);
        }
    }

    cout << "Game over!\n";
    return 0;
}