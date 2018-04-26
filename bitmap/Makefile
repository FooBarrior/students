include students.make
include tasks.make


length = $(shell lst=($(1)); echo $${\#lst[@]})

define shuffle =
$(shell bash -c '
	# thanks https://stackoverflow.com/a/17581317/1863511
	(RANDOM=13372018; lst=($(1))
	for s in "$${lst[@]}"
	do printf "%06d  \"%s\"\n" $$RANDOM "$$s"
	done) | sort -n | cut -c8-')
endef

n ::= $(call length,$(students))
students ::= $(call shuffle,$(students))

task_n ::= $(call length, $(tasks))

query ::= $(MAKECMDGOALS)
rev_query ::= $(lastword $(query)) $(firstword $(query))

define get_task =
$(shell bash -c '
	num=1;
	for s in $(students);
	do if [ "$$s" = "$(query)" ];
	then
		name=$${s[1]};
		surname=$${s[2]};
		break;
	elif [ "$$s" = "$(rev_query)" ];
	then
		surname=$${s[1]};
		name=$${s[2]};
		break;
	fi;
	((num++));
	done;
	tasks=($(tasks))

	if [[ $$num -gt $(n) ]]
	then echo No student $(query)
	else echo "$${tasks[$$((num % $(task_n)))]}"
	fi')
endef

dumb: print # avoid error with empty command

print:
ifeq ($(words $(MAKECMDGOALS)),2)
	@echo "$(get_task)"
else
	@echo "usage: make <name> <surname>"
endif


%: print
	@:
