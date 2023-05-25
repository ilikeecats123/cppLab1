from donationalerts import Alert

alert = Alert("VcTsCXa7yvIVfpymF8Ah8Pjot9UaXR5rANhN4T09")


@alert.event()
def new_donation(event):
	print(event)