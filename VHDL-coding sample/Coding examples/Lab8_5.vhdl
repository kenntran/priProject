LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab8_5 IS
PORT (X,rst: IN STD_LOGIC;
Q: OUT STD_LOGIC_VECTOR(2 DOWNTO 0));
END Lab8_5;

ARCHITECTURE BitCounter OF Lab8_5 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
signal tmp:STD_LOGIC_VECTOR (2 downto 0);
BEGIN
P0:PROCESS(X,clk,tmp,rst) 
BEGIN
clk <= not clk after PERIOD/2;		-- Generating clock, the period = 50ns. 
IF(rst = '1') then			-- After press rst, tmp = 000
	 tmp<="000";
ELSIF(X = '0') THEN			-- When X = 0, tmp = 000 and count to 110
	
	IF (clk'event and clk='1') THEN	
		tmp <= "000";
		IF(tmp >= "000") THEN 			 
			tmp <= tmp + 2;
		END IF;
	END IF;
		
ELSIF( X = '1' ) THEN 			-- When X = 1 change tmp = 001 and count to 111
	
	IF (clk'event and clk='1') THEN	
		tmp <= "001";
		IF(tmp >= "001") THEN			
			tmp <= tmp + 2;
		END IF;
	END IF;	

END IF;
END PROCESS P0;
Q <= tmp;				-- The Output
END BitCounter;

