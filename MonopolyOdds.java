import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Map.Entry;

class MonopolyOdds {

    public static Random ran = new Random();

    public static int diceSides = 4;

    public static int numberOfPlays = (int) Math.pow(10, 10);

    public static Map<String, Integer> landingData = new HashMap<String, Integer>();

    public static String squaresNames[] = {
            "GO",
            "A1",
            "CC1",
            "A2",
            "T1",
            "R1",
            "B1",
            "CH1",
            "B2",
            "B3",
            "JAIL",
            "C1",
            "U1",
            "C2",
            "C3",
            "R2",
            "D1",
            "CC2",
            "D2",
            "D3",
            "FP",
            "E1",
            "CH2",
            "E2",
            "E3",
            "R3",
            "F1",
            "F2",
            "U2",
            "F3",
            "G2J",
            "G1",
            "G2",
            "CC3",
            "G3",
            "R4",
            "CH3",
            "H1",
            "T2",
            "H2"
    };

    public static String[] CCOptions = {
            "GO",
            "JAIL"
    };

    public static String[] CHOptions = {
            "GO",
            "JAIL",
            "C1",
            "E3",
            "H2",
            "R1",
            "R",
            "R",
            "U",
            "3"
    };

    public static ArrayList<String> CCpile;
    public static ArrayList<String> CHpile;

    public static ArrayList<String> boardSquares = new ArrayList<String>(Arrays.asList(squaresNames));

    public static int playerPosition = 0;
    public static int numberOfThrows = 0;

    public static void main(String[] args) {

        createCCpile();
        createCHpile();
        shufflePiles();

        while (numberOfPlays > 0) {
            playTurn();
            numberOfPlays--;
        }

        //System.out.println(landingData);
        int total = landingData.values().stream().mapToInt(Integer::intValue).sum();
        //System.out.println("Total found: " + total);
        Map<String, Double> percentagesData = new HashMap<String, Double>();
        for (Entry<String, Integer> entry : landingData.entrySet()) {
            percentagesData.put(entry.getKey(), (double) entry.getValue() / total * 100);
        }

        percentagesData.entrySet().stream().sorted(Map.Entry.comparingByValue()).skip(boardSquares.size() - 4).forEach((entry) -> {System.out.println(boardSquares.indexOf(entry.getKey()) + " ");});
    }

    public static void playTurn() {
        //System.out.println("__________________________________________________");
        int dices[];
        numberOfThrows = 0;
        do {
            dices = getDiceRolls();
            //System.out.print("Throw! ");
        } while (dices[0] == dices[1]);
        //System.out.println();
        //System.out.println("Player square beginning of turn: " + boardSquares.get(playerPosition));
        //System.out.println("Thrown dice value: " + (dices[0] + dices[1]));
        if (numberOfThrows >= 3) {
            sendPlayerToSquare("JAIL");
            //System.out.println("Sent to jail after " + numberOfThrows + " attempts");
            return;
        }

        playerPosition += dices[0] + dices[1];
        playerPosition = playerPosition % boardSquares.size();

        String currSquareName = boardSquares.get(playerPosition);

        if (currSquareName.startsWith("CC")) {
            String card = getNextCCCardAndSwap();
            //System.out.println("Picked CC card: " + card);
            if (!card.equals("")) {
                moveBecauseOfCard(card);
            } else {
                addLandingData(boardSquares.get(playerPosition));
            }
            return;
        }

        if (currSquareName.startsWith("CH")) {
            String card = getNextCHCardAndSwap();
            //System.out.println("Picked CH card: " + card);
            if (!card.equals("")) {
                moveBecauseOfCard(card);
            } else {
                addLandingData(boardSquares.get(playerPosition));
            }
            return;
        }

        switch (currSquareName) {
            case "G2J":
                //System.out.println("Landed on G2J");
                sendPlayerToSquare("JAIL");
                break;
            default:
                addLandingData(boardSquares.get(playerPosition));
                break;
        }
    }

    public static int[] getDiceRolls() {
        numberOfThrows += 1;
        return new int[] {
                rollDice(),
                rollDice()
        };
    }

    private static int rollDice() {
        return ran.nextInt(diceSides) + 1;
    }

    public static void createCCpile() {
        CCpile = new ArrayList<String>(Arrays.asList(CCOptions));
        for (int i = 0; i < 14; i++) {
            CCpile.add("");
        }
    }

    public static void createCHpile() {
        CHpile = new ArrayList<String>(Arrays.asList(CHOptions));
        for (int i = 0; i < 6; i++) {
            CHpile.add("");
        }
    }

    public static String getNextCHCardAndSwap() {
        //System.out.println("CH Pile before : " + CHpile.toString());
        String temp = CHpile.get(0);
        CHpile.add(temp);
        CHpile.remove(0);
        //System.out.println("CH Pile after : " + CHpile.toString());
        return temp;
    }

    public static String getNextCCCardAndSwap() {
        //System.out.println("CC Pile before : " + CCpile.toString());
        String temp = CCpile.get(0);
        CCpile.add(temp);
        CCpile.remove(0);
        //System.out.println("CC Pile after : " + CCpile.toString());
        return temp;
    }

    public static void shufflePiles() {
        ArrayList<String> tempCC = new ArrayList<>(CCpile);
        ArrayList<String> tempCH = new ArrayList<>(CHpile);

        CCpile.clear();
        CHpile.clear();

        for (int i = 0; i < 16; i++) {
            int randomIndexCC = ran.nextInt(tempCC.size());
            int randomIndexCH = ran.nextInt(tempCH.size());

            CCpile.add(tempCC.get(randomIndexCC));
            CHpile.add(tempCH.get(randomIndexCH));

            tempCC.remove(randomIndexCC);
            tempCH.remove(randomIndexCH);
        }
    }

    public static void addLandingData(String squareName) {
        if (landingData.containsKey(squareName)) {
            landingData.put(squareName, landingData.get(squareName) + 1);
        } else {
            landingData.put(squareName, 1);
        }
        //System.out.println("Landed on " + squareName);
    }

    public static void sendPlayerToSquare(String squareName) {
        playerPosition = boardSquares.indexOf(squareName);
        addLandingData(squareName);
    }

    public static void playerBack3Steps() {
        playerPosition -= 3;
        playerPosition = playerPosition % boardSquares.size();
        addLandingData(boardSquares.get(playerPosition));
    }

    public static void playerGoToNextCompany(String companyPrefix) {
        for (int i = playerPosition; i < playerPosition + boardSquares.size(); i++) {
            if (boardSquares.get(i % boardSquares.size()).startsWith(companyPrefix)) {
                playerPosition = i % boardSquares.size();
                addLandingData(boardSquares.get(playerPosition));
                return;
            }
        }
    }

    public static void moveBecauseOfCard(String cardName) {
        switch (cardName) {
            case "3":
                playerBack3Steps();
                return;
            case "R":
                playerGoToNextCompany("R");
                return;
            case "U":
                playerGoToNextCompany("U");
                return;
            default:
                sendPlayerToSquare(cardName);
        }
    }

}