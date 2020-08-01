#  Unauthd

A local privilege escalation chain from user to kernel for MacOS <=10.15.5.

## How does it work? 

I wrote a blogpost explaining the vulnerabilities and exploitation methods I used. It can be found [here](https://a2nkf.github.io/unauthd_Logic_bugs_FTW/).

## How do I use it?

Build and run the `unauthd` target in the included xcode project. It will hijack the `acfs.kext` print a message to the kernel log and register the `debug.A2nkF.pwned` sysctl.
Run `sysctl debug.A2nkF.pwned` to verify, that the exploit has worked. 
This is the expected output:

```
~$ sysctl debug.A2nkF.pwned
debug.A2nkF.pwned: --- Kernel pwned ---
```

And this is the expected exploit output:
```
[~] Fakesigning myself with entitlements...
[+] Done!
[+] Got authorization!
[~] Requesting rights...
[*] Copy rights returned 0
[+] Success!
[~] Preparing Stage2...
[+] Logger registerd!
[~] Installing Payload...
[+] Package created!
[~] Sending install request now!
[+] Logger started! Waiting for stage 2... 
[STAGE2] [*] Stage started!
[STAGE2] [+] Running as uid 0x0
[STAGE2] [+] SIP bypassed ;) Preparing Stage 3...
[STAGE2] [~] Getting kext!
[STAGE2] [1] Started kextutil...
[STAGE2] [2] Performed overwrite...
[STAGE2] [3] Loading kext...
[STAGE2] [3] Running kext...
[STAGE2] [+] Kernel pwned!
[STAGE2] [~] Cleaning up our mess... 
[FINAL] [+] Done!
```

The exploit has been tested on:
```
Darwin MacBookPro.local 19.3.0 Darwin Kernel Version 19.3.0: Thu Jan  9 20:58:23 PST 2020; root:xnu-6153.81.5~1/RELEASE_X86_64 x86_64
```

## Hacking

You might have noticed, that the system preferences window popps up after the exploit has run. Just add a 
```c
while(1) {}
```
after the call to `loadKext()` in `stage2/main.c` to avoid that.

If you want to modify the exploit, here's what you need to know:

### Building

The XCode project has three build targets: `unauthd`, `kernel` and `stage2`.
After applying your changes:

1. Build the `kernel` target and copy the binary over to `/kernel` on `Disk.dmg`
2. Build the `stage2` target and copy the binary over to `/System/Library/CoreServices/Applications/Feedback Assistant.app/Contents/Library/LaunchServices/seedusaged` on `Disk.dmg`
3. Build and run the `unauthd` target

### Payloads

**Custom kernel payload**:
Add a custom payload to `kernel/kernel.c`. Note: You might need to change the  `VICTIM_KEXT` variable in `stage2/main.c` to a 
kext that is linked with the symbols you require, or do the symbol resolving dynamically.

**Custom SIPless root payload**: 
Add a custom payload to `stage2/main.c` after the call to `loadKext()`.

**Custom authd payload**:
This part is a bit more tricky, you'll need to reverse engineer the framework implementing the APIs for a desired right, implement a client module in `unauthd/modules/<yourmodule>.m` and call it from `unauthd/main.m`. 

### Files

`kernel`: Kernel Payload 

`resources`: Malicious DMG, entitlements and exploitable apple signed PKG

`stage2`: `kextutil` exploit + minimal mach logger client

`unauthd`: `authd` and `system_installd` exploit + minimal mach logger server

`unauthd/modules`: clients for private frameworks
