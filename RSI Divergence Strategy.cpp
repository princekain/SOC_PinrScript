//@version=4
strategy("RSI Divergence", overlay=true)

// Define input parameters
rsi_length = input(14, title="RSI Length")
rsi_overbought = input(70, title="RSI Overbought Level")
rsi_oversold = input(30, title="RSI Oversold Level")

// Calculate RSI
rsi_value = rsi(close, rsi_length)

// Calculate price and RSI divergences
bullish_divergence = (low[1] < low and rsi_value[1] > rsi_value)
bearish_divergence = (high[1] > high and rsi_value[1] < rsi_value)

// Generate buy and sell signals
long_condition = bullish_divergence and rsi_value < rsi_oversold
short_condition = bearish_divergence and rsi_value > rsi_overbought

// Execute trades
strategy.entry("Buy", strategy.long, when=long_condition)
strategy.entry("Sell", strategy.short, when=short_condition)