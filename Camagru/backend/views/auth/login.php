<?php
header('X-Frame-Options: DENY');
header('X-XSS-Protection: 1; mode=block');
header('X-Content-Type-Options: nosniff');
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login - Camagru</title>
    <link rel="stylesheet" href="/public/assets/css/auth.css">
    <link rel="icon" href="data:," />

</head>
<body>
<div class="shooting-stars-container">
    <div class="shooting-star" style="--shoot-top: 10%; --shoot-left: 5%; --shoot-duration:4s; --shoot-delay:1s;"></div>
    <div class="shooting-star" style="--shoot-top: 20%; --shoot-left: 15%; --shoot-duration:5s; --shoot-delay:2s;"></div>
    <div class="shooting-star" style="--shoot-top: 30%; --shoot-left: 2%; --shoot-duration:4.5s; --shoot-delay:3s;"></div>
    <div class="shooting-star" style="--shoot-top: 40%; --shoot-left: 10%; --shoot-duration:6s; --shoot-delay:4s;"></div>
    <div class="shooting-star" style="--shoot-top: 50%; --shoot-left: 1%; --shoot-duration:5s; --shoot-delay:5s;"></div>
</div>
    <div class="container">
        <h1>Login</h1>
        
        <?php if(isset($_SESSION['error'])): ?>
            <div class="alert alert-error">
                <?php echo htmlspecialchars($_SESSION['error']); unset($_SESSION['error']); ?>
            </div>
        <?php endif; ?>

        <?php if(isset($_SESSION['success'])): ?>
            <div class="alert alert-success">
                <?php echo htmlspecialchars($_SESSION['success']); unset($_SESSION['success']); ?>
            </div>
        <?php endif; ?>

        <form action="/auth/login" method="POST" class="form" autocomplete="off">
            <input type="hidden" name="csrf_token" value="<?php echo htmlspecialchars($_SESSION['csrf_token']); ?>">
            
            <div class="form-group">
                <label for="email">Email</label>
                <input type="email" 
                       id="email" 
                       name="email" 
                       required 
                       class="form-control"
                       autocomplete="off">
            </div>

            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" 
                       id="password" 
                       name="password" 
                       required 
                       class="form-control"
                       autocomplete="off">
            </div>

            <button type="submit" class="btn btn-primary">Login</button>
        </form>

        <p class="text-center">
            <a href="/forgot-password">Forgot Password?</a><br>
            Don't have an account? <a href="/register">Register here</a>
        </p>
    </div>

    <script>
    document.querySelector('form').addEventListener('submit', function(e) {
        const email = document.getElementById('email');
        const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailPattern.test(email.value)) {
            e.preventDefault();
            alert('Please enter a valid email address');
            return;
        }

        const password = document.getElementById('password');
        if (password.value.length < 1) {
            e.preventDefault();
            alert('Please enter your password');
            return;
        }
    });
    </script>
    <?php require_once __DIR__ . '/../partials/footer.php'; ?>
    </body>
</html>