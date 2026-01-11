#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>

using namespace std;

// ======================
// Utility Functions
// ======================

// =====================
// Set Console SIZE
// =====================

void setConsoleSize(short width, short height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // FIRST: set buffer size larger or equal
    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // THEN: set window size
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printMenuItem(int number, const string& text) {
    cout << setw(15);
    setColor(4); // Red
    cout << number << ". ";
    setColor(7); // White
    cout << text << endl;
}

void printParagraph(const string& text) {
    cout << text << "\n\n";
}

void printDialogue(const string& text) {
    cout << text << "\n\n";
}

// ======================
// Story & Scene Functions
// ======================

void journey2Story(); // Stub defined later
void journey2Scene();
int journey2Choices();

void printN1() {
    printParagraph(
        "The village of Greyhaven lies at the outer edge of the Ashbury Kingdom,"
        "\nwhere stone roads crumble into dirt and royal banners are rarely seen."
    );

    printParagraph("You have lived here your entire life.");

    printParagraph(
        "By day, you assist Enox, the village blacksmith and former knight."
        "\nBy night, you train behind the forge with a worn sword."
    );

    printParagraph(
        "For now, Greyhaven is peaceful.\nPerhaps too peaceful."
    );
}

int beginJourneyChoices() {
    int choice;

    while (true) {
        cout << "Player Choices:\n";
        cout << "1. Train with Enox at the forge\n";
        cout << "2. Walk through the village\n";
        cout << "3. Practice alone behind the forge\n";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        }

        cout << "\nInvalid choice. Try again.\n\n";
    }
}

void beginJourneyScene() {
    system("cls");

    printN1();

    int choice = beginJourneyChoices();

    if (choice == 1) {
        cout << "\nEnox corrects your stance and sharpens your timing.\n";
        cout << "You feel closer to your dream of becoming a knight.\n";
    } else if (choice == 2) {
         cout << "\nVillagers whisper of orcs beyond the border.\n";
        cout << "Fear hangs in the air.\n";
    } else {
        cout << "\nYou train alone, pushing your limits in silence.\n";
        cout << "No one sees your effort—but it hardens you.\n";
    }

    system("pause");

    // CONVERGE BACK TO MAIN STORY
    journey2Scene();
}

void printN2() {
    printParagraph(
        "The quiet of Greyhaven feels different today. "
    );

    printParagraph(
        "You have lived here your entire life.As you move through the village," 
        "conversations falter when you draw near. Villagers speak in hushed tones,"
        "road that leads deeper into the kingdom. Near the well,\na traveling merchant gestures wildly as he speaks,"
        "his cloak still dusted with road grime and snow.");

    printParagraph(
        "You catch fragments of his story"
        "scouts gone missing... borders breached... orcs moving in numbers."
        "\nSome villagers laugh it off, calling it fearmongering. Others do not hide their worry."
        "\nThe name Ashbury Kingdom is spoken more often now, no longer with pride, but with uncertainty."
    );

    printParagraph(
        "Whatever the truth is, \nsomething is stirring beyond the borders and Greyhaven sits directly in its path."
    );
}

int journey2Choices() {
    system("cls");

    printN2();
    int choice;

    while (true) {
        cout << "Player Choices:\n";
        cout << "1.Question the traveling merchant.\n";
        cout << "   Press him for details about what he saw beyond the border.\n";
        cout << "2.Speak with Enox at the forge.\n";
        cout << "  Ask Enox what he thinks of the rumors and whether they hold any truth.\n";
        cout << "3.Ignore the rumors and return to training\n";
        cout << "  Focus on your own path and push the unease aside.";
        cout << "\n\nEnter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        }

        cout << "\nInvalid choice. Try again.\n\n";
    }
}

void Ch1o(){
    system("cls");
    printDialogue(
        "YOU:Tell me exactly what you saw."
        "\n\nThe merchant swallows and glances around, making sure no guards are listening."
    );
    printDialogue(
        "MERCHANT: I wasn't meant to see it. No one was."   
        "\n\nHe grips the strap of his pack tightly."   
        "\n\nMERCHANT:The roads near the border are quiet. Too quiet. Patrols are gone, and the villages there empty.\nNot burned. Not looted. Just... abandoned.");
    printDialogue(
        "You feel a chill run down your spine."
        "\n\nYOU: Orcs?"
        "\n\nThe merchant nods"
        "\n\nMERCHANT:Not scattered warbands. A horde. Organized. Marching like an army.\n"
        "\nHe hesitates, then adds one last details."
        "\n\nMERCHANT:And they weren't leaderless. I saw a figure walking among them—human, or close enough.");
    printDialogue(
        "The merchant steps back, as if afraid he has already said too much.\nAround you, the village seems suddenly smaller more fragile."
        "\n\nWhatever is coming,it is not a rumor anymore."
    );

}
void Ch2o(){
    system("cls");
    printDialogue(
        "YOU:People are talking. About orcs near the border."
        "\n\nEnox finally turns to you. For a moment, his eyes are not those of a blacksmith but of someone who has seen battle."
        "\n\nENOX:Rumors spread faster than fire."
        "\n\nYou hesitate, then press on."
        "\n\nYOU:Do you think they're true?"
    );
    printDialogue(
        "Enox exhales slowly and sets the hammer down."
        "\n\nENOX: Orcs don't move without reason. Not in numbers."
        "\n\nHe studies you carefully."
        "\n\nENOX:If trouble comes, it won't announce itself. It never does."
        "\n\nYou sense there is more he wants to say but doesn't."
    );
    printDialogue(
        "The forge feels colder as you step away. Enox returns to his work,\nbut his strikes are heavier now, as if he is shaping steel for a purpose beyond tools."
    );
}
void Ch3o(){
    system("cls");
    printDialogue(
        "You take your stance too stiff. Your first swing cuts only air, the blade dragging instead of flowing.\nYou try again. And again."
        "\n\nYour arms burn.\nYour footings slips.\n"
        "\nThe sword nearly tears free from your grasp."
    );
    printDialogue(
        "Frustration rises. You adjust your grip, recalling half-remembered lessons, but without correction, every mistake lingers.\n"
        "\nOne final swing goes wide, embedding the blade into the dirt"
        "\nYou stand there, breathing hard."
    );
    printDialogue(
        "For a moment, you wonder if wanting to be a knight is enough. Then you pull the sword free."
        "\n\nYou return the weapon to its place, hands shaking not from fear, but from resolve.\n"
        "\nIf strength won't come easily, you will earn it.");
}

void journey2Scene() {
    printN2();
    int choice = journey2Choices();

    if (choice == 1) {
        cout << "\nYou step closer to the merchant, the murmurs of the crowd fading as he notices you.\n";
        cout << "His eyes narrow, measuring you, before he lowers his voice.\n\n";
        system("pause");

        Ch1o();        
    } else if (choice == 2) {
        cout << "\nYou find Enox at the forge, hammer striking steel in a steady rhythm.\n";
        cout << "Sparks burst with each blow, briefly lighting the deep lines on his face.\n";
        cout << "He does not look up when you approach. The sound of the hammer slows.Then stops.\n\n";
        system("pause");
        Ch2o();
    } else {
        cout << "\nYou slip away from the forge and move toward the edge of the village,\nwhere the sounds of work fade into the soft hush of wind through wood and stone.\n";
        cout << "\nBehind the forge, you grip your sword.";
        cout << "No guidance.\nNo watchful eyes.Just you.\n\n";
        system("pause");
        Ch3o();
        }

        system("pause");
    }



void printN3(){
    printParagraph(
        ""
    );


}
// ======================
// Stub Functions
// ======================



// ======================
// Menu
// ======================

void mainMenu() {
    setConsoleSize(120, 80);
    int choice;

    while (true) {
        system("cls");

        cout << "==================================================\n\n";
        cout << setw(40) << "T H E   H O L L O W   T H R O N E\n\n";
        cout << "==================================================\n\n";
        cout << setw(40) << "A text-based story experience\n\n";
        cout << "--------------------------------------------------\n\n";

        printMenuItem(1, "Begin Journey");
        printMenuItem(2, "Exit");

        cout << "\n--------------------------------------------------\n";
        setColor(6);
        cout << "Enter your choice: ";
        setColor(7);
        cin >> choice;

        switch (choice) {
            case 1:
                beginJourneyScene();
                break;
            case 2:
                exit(0);
            default:
                cout << "\nInvalid choice.\n";
                system("pause");
        }
    }
}

// ======================
// Main
// ======================

int main() {
    mainMenu();
    return 0;
}
