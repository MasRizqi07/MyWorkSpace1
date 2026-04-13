<?php
// Mulai sesi untuk menyimpan status game
session_start();

// Inisialisasi game jika belum dimulai
if (!isset($_SESSION['target'])) {
    $_SESSION['target'] = rand(1, 100); // Angka acak antara 1-100
    $_SESSION['guesses'] = 0; // Jumlah tebakan
    $_SESSION['message'] = "Ayo tebak angka antara 1-100!"; // Pesan awal
    $_SESSION['game_over'] = false; // Status game
}

// Proses tebakan pengguna
if (isset($_POST['guess']) && !$_SESSION['game_over']) {
    $guess = (int)$_POST['guess'];
    $_SESSION['guesses']++;
    
    if ($guess < $_SESSION['target']) {
        $_SESSION['message'] = "Terlalu rendah! Coba lagi.";
    } elseif ($guess > $_SESSION['target']) {
        $_SESSION['message'] = "Terlalu tinggi! Coba lagi.";
    } else {
        $score = max(0, 100 - $_SESSION['guesses']); // Skor: 100 dikurangi jumlah tebakan
        $_SESSION['message'] = "Benar! Angkanya adalah {$_SESSION['target']}. Skor kamu: {$score} (dari 100).";
        $_SESSION['game_over'] = true;
    }
}

// Reset game jika diminta
if (isset($_POST['reset'])) {
    session_destroy();
    header("Location: " . $_SERVER['PHP_SELF']);
    exit;
}
?>

<!DOCTYPE html>
<html lang="id">

<head>
    <meta charset="UTF-8">
    <title>Game Tebak Angka</title>
    <style>
    body {
        font-family: Arial, sans-serif;
        margin: 20px;
        background-color: #e8f5e8;
        text-align: center;
    }

    .game {
        background: white;
        padding: 20px;
        border-radius: 10px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        max-width: 400px;
        margin: auto;
    }

    input {
        padding: 10px;
        margin: 10px;
        width: 80%;
    }

    button {
        padding: 10px 20px;
        background: #4CAF50;
        color: white;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        margin: 5px;
    }

    button:hover {
        background: #45a049;
    }

    .message {
        font-size: 18px;
        margin: 20px 0;
        color: #333;
    }

    .score {
        font-weight: bold;
        color: #ff5722;
    }
    </style>
</head>

<body>
    <h1>Game Tebak Angka</h1>
    <div class="game">
        <p class="message"><?php echo $_SESSION['message']; ?></p>
        <?php if (!$_SESSION['game_over']): ?>
        <form method="post">
            <input type="number" name="guess" min="1" max="100" placeholder="Masukkan tebakanmu (1-100)" required>
            <br>
            <button type="submit">Tebak!</button>
        </form>
        <?php endif; ?>
        <p>Jumlah tebakan: <?php echo $_SESSION['guesses']; ?></p>
        <form method="post">
            <button type="submit" name="reset">Mulai Ulang Game</button>
        </form>
    </div>
</body>

</html>