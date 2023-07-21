//@version=4
strategy("Bollinger Bands Breakout", overlay=true)

// Define input parameters
length = input(20, minval=1, title="Bollinger Bands Length")
mult = input(2.0, minval=0.1, maxval=5, title="Bollinger Bands Multiplier")

// Calculate Bollinger Bands
basis = sma(close, length)
dev = mult * stdev(close, length)
upper = basis + dev
lower = basis - dev

// Detect Breakouts
breakoutUp = close > upper[1] and close[1] <= upper[1]
breakoutDown = close < lower[1] and close[1] >= lower[1]

// Generate buy and sell signals
long_condition = breakoutUp
short_condition = breakoutDown

// Execute trades
strategy.entry("Buy", strategy.long, when=long_condition)
strategy.entry("Sell", strategy.short, when=short_condition)