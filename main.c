#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

#define F_CPU 1000000UL
#include <util/delay.h>

#include "usart.h"

#define MAP_ARRAY_SIZE 301
uint16_t PROGMEM temp[] = {
0	,
1	,
2	,
3	,
4	,
5	,
6	,
7	,
8	,
9	,
10	,
11	,
12	,
13	,
14	,
15	,
16	,
17	,
18	,
19	,
20	,
21	,
22	,
23	,
24	,
25	,
26	,
27	,
28	,
29	,
30	,
31	,
32	,
33	,
34	,
35	,
36	,
37	,
38	,
39	,
40	,
41	,
42	,
43	,
44	,
45	,
46	,
47	,
48	,
49	,
50	,
51	,
52	,
53	,
54	,
55	,
56	,
57	,
58	,
59	,
60	,
61	,
62	,
63	,
64	,
65	,
66	,
67	,
68	,
69	,
70	,
71	,
72	,
73	,
74	,
75	,
76	,
77	,
78	,
79	,
80	,
81	,
82	,
83	,
84	,
85	,
86	,
87	,
88	,
89	,
90	,
91	,
92	,
93	,
94	,
95	,
96	,
97	,
98	,
99	,
100	,
101	,
102	,
103	,
104	,
105	,
106	,
107	,
108	,
109	,
110	,
111	,
112	,
113	,
114	,
115	,
116	,
117	,
118	,
119	,
120	,
121	,
122	,
123	,
124	,
125	,
126	,
127	,
128	,
129	,
130	,
131	,
132	,
133	,
134	,
135	,
136	,
137	,
138	,
139	,
140	,
141	,
142	,
143	,
144	,
145	,
146	,
147	,
148	,
149	,
150	,
151	,
152	,
153	,
154	,
155	,
156	,
157	,
158	,
159	,
160	,
161	,
162	,
163	,
164	,
165	,
166	,
167	,
168	,
169	,
170	,
171	,
172	,
173	,
174	,
175	,
176	,
177	,
178	,
179	,
180	,
181	,
182	,
183	,
184	,
185	,
186	,
187	,
188	,
189	,
190	,
191	,
192	,
193	,
194	,
195	,
196	,
197	,
198	,
199	,
200	,
201	,
202	,
203	,
204	,
205	,
206	,
207	,
208	,
209	,
210	,
211	,
212	,
213	,
214	,
215	,
216	,
217	,
218	,
219	,
220	,
221	,
222	,
223	,
224	,
225	,
226	,
227	,
228	,
229	,
230	,
231	,
232	,
233	,
234	,
235	,
236	,
237	,
238	,
239	,
240	,
241	,
242	,
243	,
244	,
245	,
246	,
247	,
248	,
249	,
250	,
251	,
252	,
253	,
254	,
255	,
256	,
257	,
258	,
259	,
260	,
261	,
262	,
263	,
264	,
265	,
266	,
267	,
268	,
269	,
270	,
271	,
272	,
273	,
274	,
275	,
276	,
277	,
278	,
279	,
280	,
281	,
282	,
283	,
284	,
285	,
286	,
287	,
288	,
289	,
290	,
291	,
292	,
293	,
294	,
295	,
296	,
297	,
298	,
299	,
300	

};
                           
uint16_t PROGMEM val[] = {
792	,
790	,
787	,
785	,
783	,
780	,
778	,
775	,
773	,
771	,
768	,
766	,
763	,
761	,
759	,
756	,
754	,
752	,
749	,
747	,
745	,
742	,
740	,
738	,
735	,
733	,
731	,
728	,
726	,
724	,
721	,
719	,
717	,
714	,
712	,
710	,
708	,
705	,
703	,
701	,
699	,
696	,
694	,
692	,
690	,
687	,
685	,
683	,
681	,
679	,
676	,
674	,
671	,
669	,
667	,
665	,
663	,
660	,
658	,
656	,
654	,
652	,
650	,
648	,
645	,
643	,
641	,
639	,
637	,
635	,
633	,
631	,
628	,
626	,
624	,
622	,
620	,
618	,
616	,
614	,
612	,
610	,
608	,
606	,
604	,
602	,
600	,
598	,
596	,
594	,
592	,
590	,
588	,
586	,
584	,
582	,
580	,
578	,
576	,
574	,
572	,
570	,
568	,
566	,
564	,
562	,
560	,
558	,
556	,
555	,
553	,
551	,
549	,
547	,
545	,
543	,
541	,
539	,
538	,
536	,
534	,
532	,
530	,
528	,
527	,
525	,
523	,
521	,
519	,
517	,
516	,
514	,
512	,
510	,
509	,
507	,
505	,
503	,
502	,
500	,
498	,
496	,
495	,
493	,
491	,
489	,
488	,
486	,
484	,
483	,
481	,
479	,
477	,
476	,
474	,
472	,
471	,
469	,
467	,
466	,
464	,
462	,
461	,
459	,
458	,
456	,
454	,
453	,
451	,
450	,
448	,
446	,
445	,
443	,
442	,
440	,
438	,
437	,
435	,
434	,
432	,
431	,
429	,
428	,
426	,
425	,
423	,
422	,
420	,
419	,
417	,
416	,
414	,
413	,
411	,
410	,
408	,
407	,
405	,
404	,
402	,
401	,
399	,
398	,
396	,
395	,
394	,
392	,
391	,
389	,
388	,
387	,
385	,
384	,
382	,
381	,
380	,
378	,
377	,
376	,
374	,
373	,
371	,
370	,
369	,
367	,
366	,
365	,
363	,
362	,
361	,
360	,
358	,
357	,
356	,
354	,
353	,
352	,
351	,
349	,
348	,
347	,
346	,
344	,
343	,
342	,
341	,
339	,
338	,
337	,
335	,
334	,
333	,
332	,
330	,
329	,
328	,
327	,
326	,
324	,
323	,
322	,
321	,
319	,
318	,
317	,
316	,
315	,
314	,
312	,
311	,
310	,
309	,
308	,
307	,
305	,
304	,
303	,
302	,
301	,
300	,
299	,
297	,
296	,
295	,
294	,
293	,
292	,
291	,
290	,
289	,
288	,
287	,
285	,
284	,
283	,
282	,
281	,
280	,
279	,
278	

};

uint16_t PROGMEM potTempArray[] = {
50	,
60	,
70	,
80	,
90	,
100	,
110	,
120	,
125	,
130	,
135	,
140	,
145	,
150	,
155	,
160	,
165	,
170	,
175	,
180	,
182	,
184	,
186	,
188	,
190	,
192	,
194	,
196	,
198	,
200	,
202	,
204	,
206	,
208	,
210	,
212	,
214	,
216	,
218	,
220	,
222	,
224	,
226	,
228	,
230	,
232	,
234	,
236	,
238	,
240	,
242	,
244	,
246	

};
                           
#define TEMP_AVERAGE_ARRAY_SIZE 10
uint8_t full = 0;
uint8_t ti = 0;
uint16_t tempAverageArray[TEMP_AVERAGE_ARRAY_SIZE];

volatile uint16_t time = 0;
volatile uint16_t timeSeconds = 0;

volatile uint16_t potTemp = 0;
volatile uint16_t temperature = 0;

volatile uint8_t display[6];

volatile uint8_t heating = 0;

volatile uint8_t firstRun = 1;

#define DA 3 //PD
#define DB 4 //PD
#define DC 1 //PB
#define DD 6 //PD
#define DE 7 //PD
#define DF 2 //PD
#define DG 0 //PB
#define DP 5 //PD

uint8_t getSegments(uint8_t digit) {
	switch(digit) {
		case 0: return 1<<DA | 1<<DB | 1<<DC | 1<<DD | 1<<DE | 1<<DF;
		break;
		case 1: return 1<<DB | 1<<DC;
		break;
		case 2: return 1<<DA | 1<<DB | 1<<DD | 1<<DE | 1<<DG;
		break;
		case 3: return 1<<DA | 1<<DB | 1<<DC | 1<<DD | 1<<DG;
		break;
		case 4: return 1<<DB | 1<<DC | 1<<DF | 1<<DG;
		break;
		case 5: return 1<<DA | 1<<DC | 1<<DD | 1<<DF | 1<<DG;
		break;
		case 6: return 1<<DA | 1<<DC | 1<<DD | 1<<DE | 1<<DF | 1<<DG;
		break;
		case 7: return 1<<DA | 1<<DB | 1<<DC;
		break;
		case 8: return 1<<DA | 1<<DB | 1<<DC | 1<<DD | 1<<DE | 1<<DF | 1<<DG;
		break;
		case 9: return 1<<DA | 1<<DB | 1<<DC | 1<<DD | 1<<DF | 1<<DG;
	}
	return 0;
}

void setDisplay1(uint16_t value, uint8_t p) {
	if (value==1000) {
		display[0] = 0;
		display[1] = 1<<DA | 1<<DB | 1<<DC | 1<<DD | 1<<DE | 1<<DF;
		display[2] = 1<<DC | 1<<DE | 1<<DG;
		
	}
	else if (value==0) {
		display[0] = 1<<DA | 1<<DB | 1<<DC | 1<<DD | 1<<DE | 1<<DF;
		display[1] = display[2] = 1<<DA | 1<<DE | 1<<DF | 1<<DG;
	}
	else {
		if (value>=100)
			display[0] = getSegments(value/100);
		else
			display[0] = 0;
			
		display[1] = getSegments((value/10)%10);
		
		display[2] = getSegments(value%10);
	}
	if (p & 1)
		display[0] |= (1<<DP);
	if (p & 2)
		display[1] |= (1<<DP);
	if (p & 4)
		display[2] |= (1<<DP);
}
	
void setDisplay2(uint16_t value, uint8_t p, uint8_t h) {
	if (h) {
		display[3] = getSegments(value/10) | (1<<DP);
		display[4] = getSegments(value%10);
		display[5] = (1<<DC) | (1<<DE) | (1<<DF) | (1<<DG);
		return;
	}
	if (value>=100)
		display[3] = getSegments(value/100);
	else
		display[3] = 0;
	if (p & 1)
		display[3] |= (1<<DP);
		
	display[4] = getSegments((value/10)%10);
	if (p & 2)
		display[4] |= (1<<DP);

	display[5] = getSegments(value%10);
	if (p & 4)
		display[5] |= (1<<DP);
}

uint16_t measureTemp (void) {
	uint16_t total = 0;
	
	
	ADMUX = 5 | (1<<REFS0) | (1<<REFS1);
	uint8_t i = 0;
	for (; i < 10; i++ ) {
		
		ADCSRA |= (1<<ADSC);
		while (!(ADCSRA & (1<<ADIF)));
	
		total  += ((ADCL) | ((ADCH)<<8));
		
	}
	
	uint16_t result = total / 10;
	
	//setDisplay1(result, 0);
	
	SendInt(result);
	SendString(", ");
	
	if (result>1020)
		return 0;
		
	if (result<10)
		return 1000;
	
	
	uint16_t value1;
	
	for (; i < MAP_ARRAY_SIZE; i++ ) {
		value1 = pgm_read_word(&(val[i]));
		if (value1 <= result)
			break;
	}
	
	if (i==MAP_ARRAY_SIZE)
		return 300;
		
	if (i==0)
		return 0;
		
	uint16_t value2 = pgm_read_word(&(val[i-1]));
		
	if (result > (value1+value2)/2)
		i--;
	
	return pgm_read_word(&(temp[i]));
}

void addTempToAverageArray (uint16_t t) {
	tempAverageArray[ti++] = t;
	if (ti == TEMP_AVERAGE_ARRAY_SIZE) {
		ti = 0;
		full = 1;
	}
}

void resetTempAvarageArray (void) {
	full = 0;
	ti = 0;	
}

uint16_t getAverageArrayTemp (void) {
	uint16_t sum = 0;
	
	if (full==0 && ti==0)
		return 0;
	
	int i;
	cli();
	for (i = 0; i < TEMP_AVERAGE_ARRAY_SIZE && (full==1 || i < ti); i++ ) {
		sum += tempAverageArray[i];
	}
	sei();
	
	return sum / i;
}

void getPotTemp(void) {
	cli();
	
	ADMUX = 0;
	ADCSRA |= (1<<ADSC);
	while (!(ADCSRA & (1<<ADIF)));
	
	uint16_t result = ((ADCL) | ((ADCH)<<8));

	sei();
	
	uint8_t i = result / 20;
	
	uint8_t o = result % 20;
	
	if (potTemp != 0 && (o < 8 || o >= 12))
		return;
		
	if (i>51)
		i = 51;
	
	potTemp = pgm_read_word(&(potTempArray[i]));
}

void setHeating(uint8_t state) {
	heating = state;
	if (heating==1)
		PORTD |= 0x01;
	else
		PORTD &= ~0x01;
}

uint8_t digit = 0;
ISR(TIMER0_OVF_vect) { // runs every 262144 ticks
	PORTB = 0b00111111;
	PORTD = (PORTD & 0b00000011) | (display[digit] & 0b11111100);
	PORTB = (display[digit]<<6) | 0b00111111;
	PORTB = (PORTB | 0b00111111) & ~(1<<digit);
	
	digit++;
	digit %= 6;
}

ISR(TIMER1_COMPA_vect) { // runs every 14 999 808 ticks
	uint16_t t = measureTemp();
	uint16_t p = 0;
	uint8_t h = heating;
	
	if (time>0) {
		timeSeconds += 15;
		if (timeSeconds >= 1800) {
			time -= 5;
			timeSeconds = 0;
		}
	}
	
	if (t==0) {
		h = 1;
		resetTempAvarageArray();
		temperature = 1000;
	}
	else if (t==1000) {
		h = 0;
		resetTempAvarageArray();
		temperature = 0;
	} 
	else {
		addTempToAverageArray(t);
		temperature = getAverageArrayTemp();
	
		if (heating==0 && temperature <= potTemp-3 && firstRun == 0)
			h = 1;
		else if (heating==1 && temperature > potTemp+3)
			h = 0;
		
		p = 2;
	}
	
	firstRun = 0;
	
	if (time>0) {
		setDisplay2(time, 0, 1);
		h = 0;
	}
	else
		setDisplay2(potTemp, 2, 0);
	
	setHeating(h);
	setDisplay1(temperature, p+h*4);
}

int main(void)
{	
	DDRB = 0xff;
	PORTB = 0b11111100;
	
	DDRC = 0x00;
	PORTC = 0x02;
	
	DDRD = 0xff;
	PORTD = 0x00;
	
	// configure ADC
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
	
	// configure timers
	TIMSK |= (1<<TOIE0) | (1<<OCIE1A);
	
	TCNT0 = 0;
	TCCR0 |= (1<<CS01);
	
	TCNT1 = 58400;
	ICR1 = 58593;
	TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS12);
	
	sei();
	
	getPotTemp();
	setDisplay2(potTemp, 2, 0);
  	
	while (1) {
		uint16_t oldPotTemp = potTemp;
		
		getPotTemp();
		
		if (potTemp != oldPotTemp) {
			cli();
			setDisplay2(potTemp, 2, 0);
			
			TCNT1 = 46874;
			
			sei();
		}
		
		if (!(PINC & 0x02)) {
			time += 5;
			timeSeconds = 0;
			if (time > 95)
				time = 5;
				
			setDisplay2(time, 0, 1);
			
			_delay_ms(100);
			
			uint16_t count = 0;
			while(!(PINC & 0x02)) {
				count++;
				_delay_ms(10);
				
				if (count>=100) {
					time = 0;
					setDisplay2(potTemp, 2, 0);
				}
			}
			
			TCNT1 = 46874;
		}
		_delay_ms(10);
	}

	return 0;
}
