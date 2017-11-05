#!/usr/bin/python

#Scipt file to configure inital setting for RPI
#Setting wifi network
#Setting IP static - 192.168.0.200
#Creating SSH key
#Passing public key to RPI to connect SSH passwordless
#I have used the code of Pibake for wifi setting
#02/11/2017


import sys, os, time

#Setting Wifi


openWifi = """

network={
ssid="WIFI-SSID"
scan_ssid=1
key_mgmt=NONE
}"""

wepWifi = """

network={
ssid="WIFI-SSID"
scan_ssid=1
key_mgmt=NONE
wep_key0="WIFI-PSK"
}"""

wpaWifi = """

network={
ssid="WIFI-SSID"
scan_ssid=1
key_mgmt=WPA-PSK
psk="WIFI-PSK"
}"""

wifiSSID = sys.argv[1]
wifiPSK = sys.argv[2]
wifiType = sys.argv[3]

if wifiSSID != "" and wifiType != "":
	if wifiPSK == "" or wifiType == "Open (no password)":
		wifiText = openWifi.replace("WIFI-SSID", wifiSSID)
	elif wifiType == "WEP":
	        wifiText = wepWifi.replace("WIFI-SSID", wifiSSID).replace("WIFI-PSK", wifiPSK)
	elif wifiType == "WPA/WPA2":
	        wifiText = wpaWifi.replace("WIFI-SSID", wifiSSID).replace("WIFI-PSK", wifiPSK)

with open("/etc/wpa_supplicant/wpa_supplicant.conf", "a") as wifiFile:
	wifiFile.write(wifiText)


os.system("wpa_cli reconfigure")

#Setting IP static

Static = """

interface eth0

static ip_address=192.168.0.10/24
static routers=192.168.0.1
static domain_name_servers=192.168.0.1

interface wlan0

static ip_address=192.168.0.200/24
static routers=192.168.0.1
static domain_name_servers=192.168.0.1

"""

with open("/etc/dhcpcd.conf", "a") as wifiFile:
	wifiFile.write(Static)


#Adding new user
os.system("""adduser buildingenergy --gecos "First Last,RoomNumber,WorkPhone,HomePhone" --disabled-password""")
os.system("""echo "buildingenergy:password" | chpasswd """)


#Allow user run command in sudo mode without passwd
sudoText = " buildingenergy ALL= NOPASSWD: ALL "

with open("/etc/sudoers", "a") as sudoFile:
	sudoFile.write(sudoText)


#Enable ssh service
os.system("systemctl enable ssh")

#Creating new SSH key
os.system("mkdir -p /home/buildingenergy/.ssh")
os.system("chown buildingenergy /home/buildingenergy/.ssh")
os.system("ssh-keygen -t rsa -C buildingenergy@raspberrypi -f /home/buildingenergy/.ssh/id_rsa -N '' ")
os.system("touch /home/buildingenergy/.ssh/authorized_keys")
os.system("chmod 755 /home/buildingenergy/.ssh/authorized_keys")


#Adding ssh public key
#Jonathan 
Jonathan = """  """

with open("/home/buildingenergy/.ssh/authorized_keys", "a") as JonaFile:
	JonaFile.write(Jonathan)

#Minna
Minna = """  """

with open("/home/buildingenergy/.ssh/authorized_keys", "a") as MiFile:
	MiFile.write(Minna)

#Nhut
Nhut = """  """

with open("/home/buildingenergy/.ssh/authorized_keys", "a") as sshFile:
	sshFile.write(Nhut)




 
time.sleep(5)
os.system("chmod +x /boot/PiBakery/blocks/initsetup/waitForNetwork.sh")
os.system("/boot/PiBakery/blocks/initsetup/waitForNetwork.sh")
