#!/usr/bin/perl

##########################################################
# Initialize Variables
##########################################################

my $prj = $ARGV[0];
#my $modem_encode = $ARGV[1];
my $modem_encode = "no";
my $modem_auth = $ARGV[2];
my $custom_dir = $ARGV[3];
my $secro_ac = $ARGV[4];

my $modem_cipher = "yes";

my $sml_dir = "mediatek/custom/$custom_dir/security/sml_auth";

my $cipher_tool = "mediatek/build/tools/CipherTool/CipherTool";
my $sign_tool = "mediatek/build/tools/SignTool/SignTool.sh";
my $secro_tool = "mediatek/build/tools/SecRo/SECRO_POST";

##########################################################
# Check Parameter
##########################################################

print "\n\n";
print "********************************************\n";
print " CHECK PARAMETER \n";
print "********************************************\n";

if (${modem_auth} eq "yes")
{
	if (${modem_encode} eq "no")
	{
		die "Error! MTK_SEC_MODEM_AUTH is 'yes' but MTK_SEC_MODEM_ENCODE is 'no'\n";
	}
}

#if (${prj} eq "mt6577_evb" || ${prj} eq "mt6577_evb_nand" || ${prj} eq "mt6517_evb")
#{
#	$modem_encode = "no"
#}

if (${prj} eq "mt6577_evb_mt" || ${prj} eq "mt6577_phone_mt" || ${prj} eq "moto77_ics")
{
	$modem_cipher = "no"
}


print "parameter check pass\n";
print "MTK_SEC_MODEM_AUTH    =  $modem_auth\n";
print "MTK_SEC_MODEM_ENCODE  =  $modem_encode\n";
print "modem_cipher  =  $modem_cipher\n";

##########################################################
# Process Modem Image
##########################################################

my $md_load = "mediatek/custom/out/$prj/modem/modem.img";
my $b_md_load = "mediatek/custom/out/$prj/modem/modem.img.bak";
my $c_md_load = "mediatek/custom/out/$prj/modem/cipher_modem.img";
my $s_md_load = "mediatek/custom/out/$prj/modem/signed_modem.img";
&process_modem_image;

$md_load = "mediatek/custom/out/$prj/modem/modem_E1.img";
$b_md_load = "mediatek/custom/out/$prj/modem/modem_E1.img.bak";
$c_md_load = "mediatek/custom/out/$prj/modem/cipher_modem_E1.img";
$s_md_load = "mediatek/custom/out/$prj/modem/signed_modem_E1.img";
&process_modem_image;

$md_load = "mediatek/custom/out/$prj/modem/modem_E2.img";
$b_md_load = "mediatek/custom/out/$prj/modem/modem_E2.img.bak";
$c_md_load = "mediatek/custom/out/$prj/modem/cipher_modem_E2.img";
$s_md_load = "mediatek/custom/out/$prj/modem/signed_modem_E2.img";
&process_modem_image;

sub process_modem_image
{
	print "\n\n";
	print "********************************************\n";
	print " PROCESS MODEM IMAGE ($md_load)\n";
	print "********************************************\n";	
	
	if (-e "$b_md_load")
	{
		print "already processed ... \n";
	}
	else
	{
		if (-e "$md_load")
		{
			system("cp -f $md_load $b_md_load") == 0 or die "can't backup modem image";
	
			########################################		
			# Encrypt and Sign Modem Image
			########################################		
			if (${modem_encode} eq "yes")
			{
				if (${modem_cipher} eq "yes")
				{
					system("./$cipher_tool ENC $sml_dir/SML_ENCODE_KEY.ini $sml_dir/SML_ENCODE_CFG.ini $md_load $c_md_load") == 0 or die "Cipher Tool return error\n";
				
					if(-e "$c_md_load")
					{
						system("rm -f $md_load") == 0 or die "can't remove original modem binary\n";
						system("mv -f $c_md_load $md_load") == 0 or die "can't generate cipher modem binary\n";
					}
				}
				
				system("./$sign_tool $sml_dir/SML_AUTH_KEY.ini $sml_dir/SML_AUTH_CFG.ini $md_load $s_md_load");
	
				if(-e "$s_md_load")
				{
					system("rm -f $md_load") == 0 or die "can't remove original modem binary\n";
					system("mv -f $s_md_load $md_load") == 0 or die "can't generate signed modem binary\n";
				}			
			}
			else
			{
				print "doesn't execute Cipher Tool and Sign Tool ... \n";
			}		
		}
	}
}

##########################################################
# Fill AC_REGION
##########################################################

print "\n\n";
print "********************************************\n";
print " Fill AC_REGION \n";
print "********************************************\n";

my $secro_def_cfg = "mediatek/custom/common/secro/SECRO_DEFAULT_LOCK_CFG.ini";
my $secro_out = "mediatek/custom/$custom_dir/secro/AC_REGION";
my $secro_script = "mediatek/build/tools/SecRo/secro_post.pl";
system("./$secro_script $secro_def_cfg $prj $custom_dir $secro_ac $secro_out") == 0 or die "SECRO post process return error\n";

##########################################################
# Process SECFL.ini
##########################################################

print "\n\n";
print "********************************************\n";
print " PROCESS SECFL.ini \n";
print "********************************************\n";

my $secfl_pl = "mediatek/build/tools/sign_sec_file_list.pl";
system("./$secfl_pl $custom_dir") == 0 or die "SECFL Perl return error\n";
