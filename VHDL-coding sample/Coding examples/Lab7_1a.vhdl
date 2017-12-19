LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab7_1 IS
PORT (J,K: IN STD_LOGIC;
--clk: STD_LOGIC;
Q: OUT STD_LOGIC );
END Lab7_1;

ARCHITECTURE JKFlipFlop OF Lab7_1 IS
signal state : std_logic;
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
BEGIN
P0:PROCESS(J,K,clk) 
BEGIN
clk <= not clk after PERIOD/2;
IF rising_edge(clk) THEN				
	IF( (J OR K) = '0' ) THEN 			
		state <= state;
	
	ELSIF(J = '1' AND K = '1') THEN			
		state <= not state;
	
	ELSE 
		IF(K = '1') THEN
			state <= '0';
		ElSIF(J = '1') THEN
			state <= '1';
		END IF;
	END IF;

END IF;
END PROCESS P0;
Q <= state;
END JKFlipFlop;


